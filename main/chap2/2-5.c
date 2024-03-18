/*
Exercise 2-5.
Write the function any(s1, s2), which returns the first location in the string
s1 where any character from the string s2 occurs, or -1 if s1 contains no
characters from s2. (The standard library function strpbrk does the same job but
returns a pointer to the location.)
*/

#include <ctype.h>
#include <stdio.h>

int any(char s[], char chars[]);

int main()
{
    int loc;
    char s[] = "Hello, world!";
    char chars[] = "fa!";

    if ((loc = any(s, chars)) >= 0) {
        printf("First occurace found on index: %i\n", loc);
    } else {
        printf("No matching characters were found.\n");
    }

    return 0;
}

int any(char s[], char chars[])
{
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; chars[j] != '\0'; j++) {
            if (tolower(s[i]) == tolower(chars[j])) {
                return i;
            }
        }
    }

    return -1;
}