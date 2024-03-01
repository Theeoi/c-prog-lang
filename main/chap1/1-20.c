/*
Exercise 1-20.
Write a program 'detab' that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define N 4

int get_line(char line[], int max_line_length);
void detab(char line[]);
void copy(char to[], char from[]);

int main()
{
    char line[MAX_LINE_LENGTH];

    while ((get_line(line, MAX_LINE_LENGTH)) > 0)
    {
        detab(line);
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
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[])
{
    int nblanks, j;
    char temp[MAX_LINE_LENGTH];

    copy(temp, s);

    j = 0;
    for (int i = 0; temp[i] != '\0'; i++)
    {
        nblanks = N - (i % N);
        if (temp[i] == '\t')
        {
            while (nblanks-- > 0)
            {
                s[j++] = ' ';
            }
        }
        else
        {
            s[j++] = temp[i];
        }
    }
    s[j] = '\0';
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}