#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Helper function to make two bit strings of equal length by adding leading zeros
int makeEqualLength(char **str1, char **str2) {
    int len1 = strlen(*str1);
    int len2 = strlen(*str2);
    
    if (len1 < len2) {
        int diff = len2 - len1;
        char *newStr1 = (char *)malloc(len2 + 1);
        memset(newStr1, '0', diff); // Fill with leading zeros
        strcpy(newStr1 + diff, *str1);
        free(*str1);
        *str1 = newStr1;
        return len2;
    } else if (len1 > len2) {
        int diff = len1 - len2;
        char *newStr2 = (char *)malloc(len1 + 1);
        memset(newStr2, '0', diff); // Fill with leading zeros
        strcpy(newStr2 + diff, *str2);
        free(*str2);
        *str2 = newStr2;
        return len1;
    }
    
    return len1;
}

// Function to add two bit strings and return the result
char* addBitStrings(char *first, char *second) {
    int length = makeEqualLength(&first, &second);
    char *result = (char *)malloc(length + 2); // +1 for carry, +1 for '\0'
    result[length + 1] = '\0';

    int carry = 0;
    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';
        int sum = (firstBit ^ secondBit ^ carry);
        result[i + 1] = sum + '0';
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry) {
        result[0] = '1';
    } else {
        memmove(result, result + 1, length + 1);
    }

    free(first);
    free(second);

    return result;
}

// Function to multiply single bits
int multiplySingleBit(const char *a, const char *b) {
    return (a[0] - '0') * (b[0] - '0');
}

// Karatsuba algorithm to multiply two bit strings
long int multiply(char *X, char *Y) {
    int n = makeEqualLength(&X, &Y);

    if (n == 0) return 0;
    if (n == 1) return multiplySingleBit(X, Y);

    int fh = n / 2;   
    int sh = n - fh; 

    // Split strings into two halves
    char *Xl = (char *)malloc(fh + 1);
    char *Xr = (char *)malloc(sh + 1);
    char *Yl = (char *)malloc(fh + 1);
    char *Yr = (char *)malloc(sh + 1);

    strncpy(Xl, X, fh);
    Xl[fh] = '\0';
    strcpy(Xr, X + fh);
    strncpy(Yl, Y, fh);
    Yl[fh] = '\0';
    strcpy(Yr, Y + fh);

    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(strdup(Xl), strdup(Xr)), addBitStrings(strdup(Yl), strdup(Yr)));

    free(Xl);
    free(Xr);
    free(Yl);
    free(Yr);

    free(X);
    free(Y);

    return P1 * (1L << (2 * sh)) + (P3 - P1 - P2) * (1L << sh) + P2;
}

int main() {

    clock_t start = clock();

    printf("Resultado Karatsuba: %ld\n", multiply(strdup("64"), strdup("64")));

    sleep(1);
    clock_t end = clock();
    printf("\nTiempo de ejecucion: %.8f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
