#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to make two strings of equal length by adding leading zeros
int makeEqualLength(char **str1, char **str2) {
    int len1 = strlen(*str1);
    int len2 = strlen(*str2);
    if (len1 < len2) {
        *str1 = (char *) realloc(*str1, len2 + 1);
        memmove(*str1 + (len2 - len1), *str1, len1 + 1);
        memset(*str1, '0', len2 - len1);
        return len2;
    } else if (len1 > len2) {
        *str2 = (char *) realloc(*str2, len1 + 1);
        memmove(*str2 + (len1 - len2), *str2, len2 + 1);
        memset(*str2, '0', len1 - len2);
    }
    return len1; // If len1 >= len2
}

// Function to add two bit strings
char *addBitStrings(char *first, char *second) {
    char *result = (char *) malloc(strlen(first) + 2); // +1 for carry, +1 for '\0'
    int length = makeEqualLength(&first, &second);
    int carry = 0;

    result[length] = '\0'; // Null-terminate result string

    // Add bits from right to left
    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';
        int sum = firstBit ^ secondBit ^ carry;
        result[i + 1] = sum + '0'; // Store result bit
        carry = (firstBit & secondBit) | (carry & (firstBit ^ secondBit));
    }

    // If overflow, add leading 1
    if (carry) {
        result[0] = '1';
        return result; // Result with carry
    }
    return result + 1; // Skip leading zero
}

// Function to multiply single bits
int multiplySingleBit(char a, char b) {
    return (a - '0') * (b - '0');
}

// Main function to multiply two bit strings using the Karatsuba algorithm
long long int multiply(char *X, char *Y) {
    int n = makeEqualLength(&X, &Y);

    // Base cases
    if (n == 0) return 0;
    if (n == 1) return multiplySingleBit(X[0], Y[0]);

    int fh = n / 2;   // First half size
    int sh = n - fh;  // Second half size

    // Divide X and Y into two halves
    char *Xl = strndup(X, fh);
    char *Xr = strdup(X + fh);
    char *Yl = strndup(Y, fh);
    char *Yr = strdup(Y + fh);

    // Recursively calculate the three products
    long long int P1 = multiply(Xl, Yl);
    long long int P2 = multiply(Xr, Yr);
    char *sum1 = addBitStrings(Xl, Xr);
    char *sum2 = addBitStrings(Yl, Yr);
    long long int P3 = multiply(sum1, sum2);
    
    // Free allocated memory
    free(Xl);
    free(Xr);
    free(Yl);
    free(Yr);
    free(sum1);
    free(sum2);

    // Combine the three products
    return P1 * (1LL << (2 * sh)) + (P3 - P1 - P2) * (1LL << sh) + P2;
}
/*
int main()
{
    printf ("%ld\n", multiply("1100", "1010"));
    printf ("%ld\n", multiply("110", "1010"));
    printf ("%ld\n", multiply("11", "1010"));
    printf ("%ld\n", multiply("1", "1010"));
    printf ("%ld\n", multiply("0", "1010"));
    printf ("%ld\n", multiply("111", "111"));
    printf ("%ld\n", multiply("11", "11"));
}*/
