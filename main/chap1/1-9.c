/*
Exercise 1-9.
Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int c, blank;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            blank = FALSE;
        }

        if (!blank)
        {
            putchar(c);
        }

        if (c == ' ')
        {
            blank = TRUE;
        }
    }

    return 0;
}