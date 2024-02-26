/*
Exercise 1-10.
Write a program to copy its input to its output, replacing each tab with \t,
each backspace with \b, and each backslash with \\. This makes tabs and
backspaces visible in an unambigous way.
*/

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            c = 't';
        }
        else if (c == '\b')
        {
            putchar('\\');
            c = 'b';
        }
        else if (c == '\\')
        {
            putchar('\\');
            c = '\\';
        }

        putchar(c);
    }

    return 0;
}