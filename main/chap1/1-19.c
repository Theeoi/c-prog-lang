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
void reverse(char line[], int line_length);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line, len);

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

void reverse(char s[], int len)
{

    int nl = FALSE;

    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
        --len;
        nl = TRUE;
    }

    char temp;

    for (int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    if (nl)
    {
        ++len;
        s[len - 1] = '\n';
    }
}
