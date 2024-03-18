/*
Exercise 2-6.
Write a function setbits(x, p, n, y) that returns x with the n bits that begin
at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <ctype.h>
#include <stdio.h>

int setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
    unsigned int x = 0xFF;
    unsigned int y = 0x5A;
    int p = 12, n = 8; /* Assume rightmost bit has position 1 */

    printf("0x%X\n", setbits(x, p, n, y));

    return 0;
}

int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int nbits = ~(~0 << n);

    return (x & ~(nbits << p - n)) | ((y & nbits) << p - n);
}