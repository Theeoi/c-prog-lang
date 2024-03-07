/*
Exercise 1-24.
Write a program to check a C program for rudimentary syntax errors like
unbalanced parenthesis, brackets and braces. Don't forget about quotes, both
single and double, escape sequences, and comments, (This program is hard if you
do it in full generality.)
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int parenthesis = 0, brackets = 0, braces = 0;

void count_symbols(void);
int skip_comment(int c);
int skip_quote(int c);
void check_symbol_balance(void);

int main()
{
    count_symbols();
    check_symbol_balance();

    return 0;
}

void count_symbols(void)
{
    extern int parenthesis, brackets, braces;

    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '/' && (c = getchar()) == '*')
        {
            c = skip_comment(c);
        }
        if (c == '"' || c == '\'')
        {
            c = skip_quote(c);
        }
        if (c == '(')
        {
            ++parenthesis;
        }
        if (c == ')')
        {
            --parenthesis;
        }
        if (c == '[')
        {
            ++brackets;
        }
        if (c == ']')
        {
            --brackets;
        }
        if (c == '{')
        {
            ++braces;
        }
        if (c == '}')
        {
            --braces;
        }
    }
}

int skip_comment(int c)
{
    int in_comment = TRUE;

    while (in_comment && (c = getchar()) != EOF)
    {
        if (c == '*' && (c = getchar()) == '/')
        {
            in_comment = FALSE;
        }
    }
    return c;
}

int skip_quote(int quote)
{
    int c, in_quote = TRUE;

    while (in_quote && (c = getchar()) != EOF)
    {
        if (c == '\\')
        {
            /* skip escaped quotes */
            int n = 2;
            while (n--)
            {
                c = getchar();
            }
        }
        if (c == quote)
        {
            in_quote = FALSE;
        }
    }
    return c;
}

void check_symbol_balance(void)
{
    extern int parenthesis, brackets, braces;

    if (parenthesis < 0)
    {
        printf("Error: missing '('\n");
    }
    else if (parenthesis > 0)
    {
        printf("Error: missing ')'\n");
    }
    else
    {
        printf("Parenthesis balanced!\n");
    }
    if (brackets < 0)
    {
        printf("Error: missing '['\n");
    }
    else if (brackets > 0)
    {
        printf("Error: missing ']'\n");
    }
    else
    {
        printf("Brackets balanced!\n");
    }
    if (braces < 0)
    {
        printf("Error: missing '{'\n");
    }
    else if (braces > 0)
    {
        printf("Error: missing '}'\n");
    }
    else
    {
        printf("Braces balanced!\n");
    }
}