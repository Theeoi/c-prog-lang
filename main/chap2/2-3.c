/*
Exercise 2-3.
Write the function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f and A through F.
*/

#include <ctype.h>
#include <stdio.h>

int htoi(char s[]);

int main()
{
    char hex[] = "0x9F";

    printf("%i\n", htoi(hex));

    return 0;
}

int htoi(char s[])
{
    int i, stop, n, val;

    if (s[0] == '0' && tolower(s[1]) == 'x') {
        i = 2;
    } else {
        i = 0;
    }

    n = val = 0;
    while (s[i] != '\0') {
        if (!isdigit(s[i]) && !(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')) {
            return -1; /* non-allowed character found */
        }

        if (isdigit(s[i])) {
            val = s[i] - '0';
        } else {
            val = 10 + (tolower(s[i]) - 'a');
        }

        n = 16 * n + val;

        i++;
    }

    return n;
}