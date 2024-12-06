#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Entering the size
    unsigned int size = 0;
    printf("Enter matrix size: ");
    scanf("%u", &size);
    if (size < 2)
    {
        printf("Wrong size entered. It needs to be at least 2. Exit.\n");
    }

    // Array of pointers
    int ** matrix = (int**)malloc(size*sizeof(int*));

    if (!matrix)
    {
        printf("No memory left. Exit.\n");
        return 1;
    }

    // Each pointer to another array
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)malloc(size*sizeof(int));
        if (!matrix[i])
        {
            printf("No memory left. Exit.\n");
            return 1;
        }
    }

    // Entering matrix data
    printf("Enter matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Do calculations
    int max = 0;
    int maxColumn = -1;
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            temp += matrix[j][i];
        }
        if (temp > max)
        {
            max = temp;
            maxColumn = i;
        }
        temp = 0;
    }

    // Output results
    printf("The column, where the sum of elements below main "
           "diagonal is the biggest (%d), is %d.", max, maxColumn + 1);

    // Free up the space
    for (int i = 0; i < size; i++)
    {
        if (matrix[i])
        {
            free(matrix[i]);
        }
    }
    free(matrix);
    matrix = NULL;
}