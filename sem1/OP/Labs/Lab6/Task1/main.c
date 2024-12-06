#include <stdio.h>

#define MAXSIZE 25

void sortMatrix(int [MAXSIZE][MAXSIZE], int rows, int columns);

int main() {
    int rows = 0;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    if (rows > MAXSIZE || rows <= 1)
    {
        printf("Wrong value entered. It should be more than %d and greater than 1. End of program.", MAXSIZE);
        return 1;
    }

    int columns = 0;
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    if (columns > MAXSIZE || columns <= 0)
    {
        printf("Wrong value entered. It should be more than %d and greater than 0. End of program.", MAXSIZE);
        return 1;
    }

    printf("Matrix:\n");
    int matrix[MAXSIZE][MAXSIZE] = {0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    sortMatrix(matrix, rows, columns);

    printf("Sorted Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to sort a matrix based on the second row
void sortMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int columns)
{
    for (int i = 0; i < columns - 1; i++)
    {
        for (int j = 0; j < columns - i - 1; j++)
        {
            if (matrix[1][j] > matrix[1][j + 1])
            {
                for (int k = 0; k < rows; k++)
                {
                    // Swap elements in each row
                    int temp = matrix[k][j];
                    matrix[k][j] = matrix[k][j + 1];
                    matrix[k][j + 1] = temp;
                }
            }
        }
    }
}
