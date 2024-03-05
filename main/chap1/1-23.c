/*
Exercise 1-23.
Write a program to remove all comments from a C program. Don't forget to handle
quoted strings and character constants properly. C comments do not nest.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_quote(char prev_c, char c);

int main()
{
    int prev_c, c;                    /* holding characters */
    int in_comment, in_quote = FALSE; /* flags */

    /* holding two characters at the time */
    prev_c = getchar();
    while ((c = getchar()) != EOF)
    {
        if (is_quote(prev_c, c))
        {
            if (in_quote)
            {
                in_quote = FALSE;
            }
            else if (!in_comment)
            {
                in_quote = TRUE;
            }
        }

        if (!in_quote && prev_c == '/' && c == '*')
        {
            in_comment = TRUE;
        }
        if (!in_comment)
        {
            putchar(prev_c);
        }
        if (in_comment && prev_c == '*' && c == '/')
        {
            c = getchar();
            in_comment = FALSE;
        }
        prev_c = c;
    }
    putchar(prev_c);

    return 0;
}

int is_quote(char c1, char c2)
{
    return c1 != '\\' && c1 != '\'' && c2 == '\"';
}