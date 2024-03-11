/*
Exercise 2-2.
Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>

enum boolean
{
    FALSE,
    TRUE
};

int main()
{
    int lim = 1000, i, c, stop = FALSE;
    char s[lim];

    for (i = 0; !stop; i++)
    {
        if (i > lim - 1)
        {
            stop = TRUE;
        }
        else if ((c = getchar()) != '\n')
        {
            stop = TRUE;
        }
        else if (c == EOF)
        {
            stop = TRUE;
        }
        else
        {
            s[i] = c;
        }
    }

    return 0;
}