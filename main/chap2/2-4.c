/*
Exercise 2-4.
Write an alternative version of squeeze(s, chars) that deletes each character in s
that matches any character in string chars.
*/

#include <ctype.h>
#include <stdio.h>

void squeeze(char s[], char chars[]);

int main()
{
    char s[] = "st**r--i-ng**";
    char chars[] = "*-";

    squeeze(s, chars);

    printf("%s\n", s);

    return 0;
}

void squeeze(char s[], char chars[])
{
    int k = 0;

    for (int i = 0, j; s[i] != '\0'; i++) {
        for (j = 0; chars[j] != '\0' && s[i] != chars[j]; j++) {
            ;
        }
        if (chars[j] == '\0') {
            s[k++] = s[i];
        }
    }

    s[k] = '\0';
}