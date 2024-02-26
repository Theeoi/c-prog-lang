/*
Exercise 1-13.
Write a program to print a histogram of the lengths or words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is
more challenging.
*/

#include <stdio.h>

#define LONGEST_WORD 25

int main()
{
    int c, wl;
    int wl_hist[LONGEST_WORD];

    for (int i = 0; i < LONGEST_WORD; i++)
    {
        wl_hist[i] = 0;
    }

    wl = 0;
    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && wl > 0)
        {
            ++wl_hist[wl - 1];
            wl = 0;
        }
        else
        {
            ++wl;
        }
    }

    printf("WORD LENGTHS HISTOGRAM:\n");
    for (int i = 1; i <= LONGEST_WORD; i++)
    {
        printf("%2d|", i);
        for (int j = 0; j < wl_hist[i - 1]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}