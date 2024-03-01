/*
Exercise 1-19.
Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char line[]);

int main()
{
    char line[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0)
    {
        reverse(line);

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

void reverse(char s[])
{
    int len = 0;
    int nl = FALSE;
    char temp;

    while (s[len] != '\0')
    {
        ++len;
    }

    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
        --len;
        nl = TRUE;
    }

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
