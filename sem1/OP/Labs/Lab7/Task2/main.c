#include <stdio.h>
#include <math.h>

void tabulate1(double, double, double);

void tabulate2(double, double, double);

void tabulate3(double, double, double);

int main()
{
    const int a = 0;
    const int b = 4.5;

    double h;
    printf("Enter h: ");
    scanf("%lf", &h);

    void (*pf)(double, double, double);
    int method = 0;
    printf("Enter method(1, 2, or 3): ");
    scanf("%d", &method);

    switch (method)
    {
        case 1: pf = tabulate1; break;
        case 2: pf = tabulate2; break;
        case 3: pf = tabulate3; break;
        default: printf("Wrong number of method entered. End of program."); exit(1);
    }

    (*pf)(a, b, h);
}

void tabulate1(double a, double b, double step)
{
    // x      y
	// ...    ...
    
    printf("x\t\ty\n");
    for (; a <= b; a += step)
    {
        printf("%lf\t%lf\n", a, cbrt(2*a-1));
    }
}

void tabulate2(double a, double b, double step)
{
    // x      y
	// ...    ...
    
    printf("x\t\ty\n");
    while (a <= b)
    {
        printf("%lf\t%lf\n", a, cbrt(2*a-1));
        a += step;
    }
}

void tabulate3(double a, double b, double step)
{
    // x      y
	// ...    ...

    printf("x\t\ty\n");
    do
    {
        printf("%lf\t%lf\n", a, cbrt(2 * a - 1));
        a += step;
    } while (a <= b);
}