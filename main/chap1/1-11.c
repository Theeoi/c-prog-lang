/*
Exercise 1-11.
How would you test the word count program? What kinds of input are most likely
to uncover bugs if there are any?

Answer:
Testing should be done with a variety of inputs, both standard text pieces but
also other forms of content such as code snippets.
In we input the code of the program itself it would not be very accurate since
braces and similar things would count as words.
It is also the case that the *nc* variable is defined as an int which will
likely overflow quickly for larger pieces of input.
*/

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}