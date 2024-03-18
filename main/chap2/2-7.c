/*
Exercise 2-7.
Write a function invert(x, p, n) that returns x with the n bits that begin a
position p inverted (i.e. 1 changed to 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    unsigned int x = 0xEE;
    int p = 8, n = 4; /* Assume rightmost bit has position 1 */

    printf("0x%02X\n", invert(x, p, n));

    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int nbits = ~(~0 << n);

    return x ^ (nbits << p - n);
}