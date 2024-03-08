/*
Exercise 2-1.
Write a program to determine the ranges of char, short, int and long variables,
both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of
the various floating-point types.
*/

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    printf("== Char ==\nUnsigned:\t[%2i, %i]\n\tSigned:\t\t[%i, %i]\n\n", 0, UCHAR_MAX, SCHAR_MIN, SCHAR_MAX);
    printf("== Short ==\nUnsigned:\t[%2i, %i]\nSigned:\t\t[%i, %i]\n\n", 0, USHRT_MAX, SHRT_MIN, SHRT_MAX);
    printf("== Int ==\nUnsigned:\t[%2i, %u]\nSigned:\t\t[%i, %i]\n\n", 0, UINT_MAX, INT_MIN, INT_MAX);
    printf("== Long ==\nUnsigned:\t[%2i, %lu]\nSigned:\t\t[%li, %li]\n\n", 0, ULONG_MAX, LONG_MIN, LONG_MAX);
    printf("== Float ==\nUnsigned:\t[1e%i, 1e%i]\n\n", FLT_MIN_10_EXP, FLT_MAX_10_EXP);
    printf("== Double ==\nUnsigned:\t[1e%i, 1e%i]\n\n", DBL_MIN_10_EXP, DBL_MAX_10_EXP);
    printf("== Long Double ==\nUnsigned:\t[1e%i, 1e%i]\n\n", LDBL_MIN_10_EXP, LDBL_MAX_10_EXP);

    return 0;
}