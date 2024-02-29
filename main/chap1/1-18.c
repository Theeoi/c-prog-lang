/*
Exercise 1-18.
Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 1000

int get_line(char line[], int maxline);
int trim_right(char line[], int line_length);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        len = trim_right(line, len);
        if (len == 1 && line[0] == '\n')
        {
            line[0] = '\0';
        }

        printf("%s", line);
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

int trim_right(char s[], int len)
{
    int nl = FALSE;

    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
        --len;
        nl = TRUE;
    }

    while (len - 1 >= 0 && (s[len - 1] == ' ' || s[len - 1] == '\t'))
    {
        s[len - 1] = '\0';
        --len;
    }

    if (nl)
    {
        ++len;
        s[len - 1] = '\n';
    }

    return len;
}