/*
Exercise 1-8.
Write a program to count blanks, tabs and newlines.
*/

#include <stdio.h>

int main()
{
    int c;
    long nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++nb;
        }
        if (c == '\t')
        {
            ++nt;
        }
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("\nThe input contained %ld blanks, %ld tabs and %ld newlines.\n", nb, nt, nl);

    return 0;
}