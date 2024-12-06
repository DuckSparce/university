#include <stdio.h>
#include <conio.h>

int solvelin(double, double);

int main(int argc, char *argv[])
{
    printf("There are %d arguments\n", argc);
    if (!(argc == 4))
    {
        printf("Error - not enough or too many arguments\n");
        _getch();
        return 1;
    }
    solvelin(atof(argv[2]), atof(argv[3]));
    _getch();
    return 0;
}

int solvelin(double var1, double var2)
{
    printf("The equation to be solved is:\t%lf*x = %lf\n", var1, -var2);
    if (var1)
        printf("Result: %lf", -var2 / var1);
    else
        printf("There are no solutions");
    return 0;
}
