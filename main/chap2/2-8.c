/*
Exercise 2-8.
Write a function rightrot(x, n) that returns the value of the integer x rotated
to the right by n bit positions.
*/

#include <stdio.h>

int rightrot(unsigned int x, int n);

int main()
{
    unsigned int x = 0xABCDEF12;
    int n = 12;

    printf("0x%08X\n", rightrot(x, n));

    return 0;
}

int rightrot(unsigned int x, int n)
{
    return (x >> n) | (x << sizeof(unsigned int) * 8 - n);
}