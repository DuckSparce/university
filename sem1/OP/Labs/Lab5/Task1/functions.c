#include "functions.h"
#include <math.h>
#include <stdio.h>

double solveEquation1(double x)
{
    double result = cbrt(2 * x - 1);
    return result;
}

int solveEquation2(double x, double * destination)
{
    *destination = cbrt(2 * x - 1);

    if (*destination > 0)
    {
        return 1;
    }
    else if (*destination < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void tabulateFunction(int method)
{
    const int a = 0;
    const double b = 4.5;

    double h = 0;
    printf("Enter step h: ");
    scanf("%lf", &h);

    double x = a;
    double y = 0;
    // x      y
	// ...    ...
    if (method == 1) 
    {
	    printf("x\t\ty\n");
        while (x <= b)
        {
            y = solveEquation1(x);
            printf("%lf\t%lf\n", x, y);
            x += h;
        }
    }
    else if (method == 2)
    {
	    printf("res\tx\t\ty\n");
        while (x <= b)
        {
            int result = solveEquation2(x, &y);
            printf("%d\t%lf\t%lf\n", result, x, y);
            x += h;
        }
    }
    else
    {
        printf("Wrong method number entered. Should be 1 or 2. End of program.");
        return;
    }
}