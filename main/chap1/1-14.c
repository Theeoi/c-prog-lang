/*
Exercise 1-13.
Write a program to print a histogram of the lengths or words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is
more challenging.
*/

#include <stdio.h>

#define START_CHAR '!'
#define END_CHAR '~'
#define NUM_CHAR END_CHAR - START_CHAR + 1

int main()
{
    int c;
    int c_hist[NUM_CHAR];

    for (int i = 0; i < NUM_CHAR; i++)
    {
        c_hist[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= START_CHAR && c <= END_CHAR)
        {
            ++c_hist[c - START_CHAR];
        }
    }

    printf("CHARACTER OCCURANCE HISTOGRAM:\n");
    for (int i = 0; i < NUM_CHAR; i++)
    {
        printf("%c|", START_CHAR + i);
        for (int j = 0; j < c_hist[i]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}