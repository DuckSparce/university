#include <stdio.h>
#include "functions.h"

#define SIZE 12

int main()
{
    int vertices[SIZE] = { 0 };
    int pruferCode[SIZE - 2] = { 0 };
    printf("Enter Prufer code: ");
    for (int i = 0; i < SIZE - 2; i++)
    {
        scanf("%d", &pruferCode[i]);
    }

    buildTree(pruferCode, vertices, SIZE);

    return 1;
}