#include <stdio.h>
#include "functions.h"

int main()
{
    int method = 0;
    printf("Choose method (1 or 2): ");
    scanf("%d", &method);
    tabulateFunction(method);
}