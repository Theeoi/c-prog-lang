/*
Exercise 1-16.
Revise the main routine of the longest-line program so it will correctly print
the length of arbitrarily long input lines, and as much as possible of the text.
*/

#include <stdio.h>

#define MAXLINE 500

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, next_len;                      /* length of a line, next_len if length is over MAXLINE. */
    int max;                                /* the length of the longest line found. */
    char line[MAXLINE], cont_line[MAXLINE]; /* the current line, cont_line if longer than MAXLINE. */
    char longest[MAXLINE];                  /* the longest line found. */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len == MAXLINE - 1)
        {
            /* Mark the line continuation... */
            for (int i = 0; i < 3; i++)
            {
                line[MAXLINE - 2 - i] = '.';
            }
            line[MAXLINE - 1] = '\n';

            /* find the full length of the line. */
            next_len = len;
            while (next_len == MAXLINE - 1)
            {
                next_len = get_line(cont_line, MAXLINE);
                len += next_len;
            }
        }

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("\nLongest line is %d characters long:\n%s", max, longest);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}