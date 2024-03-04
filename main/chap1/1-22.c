/*
Exercise 1-22.
Write a program to "fold" long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make
sure your program does something intelligent with very long lines, and if there
are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define FOLD_COLUMN 80

int get_line(char line[], int max_line_length);
void fold_line(char line[], int fold_column);

int main()
{
    int len;
    char line[MAX_LINE_LENGTH];

    while ((len = get_line(line, MAX_LINE_LENGTH)) > 0)
    {
        fold_line(line, FOLD_COLUMN);
        printf("%s", line);
    }

    return 0;
}

int get_line(char s[], int maxlen)
{
    int i, c;

    for (i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void fold_line(char s[], int limit)
{
    for (int i, num_char, i_blank = 0; s[i] != '\0'; i++)
    {
        num_char++;

        /* Save the index of the last blank. */
        if (s[i] == ' ' || s[i] == '\t')
        {
            i_blank = i;
        }

        /* Only fold if we found a blank. */
        if (num_char >= limit && i_blank != 0)
        {
            s[i_blank] = '\n';
            i = i_blank;
            num_char = i_blank = 0;
        }
    }
}