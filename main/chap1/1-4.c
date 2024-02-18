/*
Exercise 1-4.
Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 160;
    step = 20;

    printf("Celsius\tFahrenheit\n");
    printf("=======\t==========\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%5.0f\t%6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}