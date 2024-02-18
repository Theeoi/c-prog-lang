/*
Exercise 1-5.
Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
*/

#include <stdio.h>

int main()
{
    int fahr;

    printf(" F \t C \n");
    printf("===\t===\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {
        printf("%3d\t%5.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }

    return 0;
}