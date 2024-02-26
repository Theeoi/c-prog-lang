/*
Exercise 1-15.
Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>

float f_to_c(float fahr);

int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit\tCelsius\n");
    printf("==========\t=======\n");

    fahr = lower;
    while (fahr <= upper)
    {
        printf("%8.0f\t%6.1f\n", fahr, f_to_c(fahr));
        fahr = fahr + step;
    }

    return 0;
}

float f_to_c(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}