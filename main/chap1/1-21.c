/*
Exercise 1-21.
Write a program 'entab' that replaces strings of blanks by the minimum number of
tabs and blanks to achieve the same spacing. Use the same tab stops as for
'detab'. When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define TAB_SPACE 4

int get_line(char line[], int max_line_length);
void entab(char line[]);
void copy(char to[], char from[]);

int main()
{
    char line[MAX_LINE_LENGTH];

    while (get_line(line, MAX_LINE_LENGTH) > 0)
    {
        entab(line);
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

void entab(char s[])
{
    int j, ntabs, nblanks;
    char temp[MAX_LINE_LENGTH];

    copy(temp, s);

    j = 0;
    for (int i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == ' ')
        {
            for (nblanks = ntabs = 0; temp[i] == ' '; i++)
            {
                if ((i + 1) % TAB_SPACE == 0)
                {
                    ++ntabs;
                    nblanks = 0;
                }
                else
                {
                    ++nblanks;
                }
            }
            i--;
            while (ntabs-- > 0)
            {
                s[j++] = '\t';
            }
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