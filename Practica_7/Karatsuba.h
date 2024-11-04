#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to make two strings of equal length by adding leading zeros
int makeEqualLength(char **str1, char **str2);

// Function to add two bit strings
char *addBitStrings(char *first, char *second);

// Function to multiply single bits
int multiplySingleBit(char a, char b);

// Main function to multiply two bit strings using the Karatsuba algorithm
long long int multiply(char *X, char *Y);
