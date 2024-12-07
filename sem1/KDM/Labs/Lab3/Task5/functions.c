#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void outputRelation(int ** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 0 - antireflexive, 1 - reflexive, 2 - neither reflexive nor antireflexive
int isReflexive(int ** matrix, int size)
{
    int result = 0;
    if (matrix[0][0])
    {
        result = 1;
        for (int i = 1; i < size; i++)
        {
            if (!matrix[i][i])
            {
                return 2;
            }
        }
    }
    else
    {
        result = 0;
        for (int i = 1; i < size; i++)
        {
            if (matrix[i][i])
            {
                return 2;
            }
        }
    }

    return result;
}

// 0 - antisymmetric, 1 - symmetric, 2 - asymmetric
int isSymmetric(int ** matrix, int size)
{
    int result = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (matrix[i][j] == matrix[j][i])
            {
                result = 0;
                if (isReflexive(matrix, size))
                {
                    result = 2;
                }
                return result;
            }
        }
    }

    return result;
}

// 0 - antitransitive, 1 - transitive, 2 - neither transitive nor antitransitive
int isTransitive(int ** matrix, int size)
{
    int ** matrix2 = (int**)malloc(size * sizeof(int*));

    if (!matrix2)
    {
        printf("No memory left. Exit.\n");
        return -1;
    }

    // Each pointer to another array
    for (int i = 0; i < size; i++)
    {
        matrix2[i] = (int*)malloc(size*sizeof(int));
        if (!matrix2[i])
        {
            printf("No memory left. Exit.\n");
            return -1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix2[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                if (matrix[i][k] && matrix[k][j])
                {
                    matrix2[i][j] = 1;
                    break;
                }
            }
        }
    }


    int isAntitransitive = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] || !matrix2[i][j])
            {
                isAntitransitive = 0;
            }
        }
    }

    int isTransitive = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!matrix[i][j] || !matrix2[i][j])
            {
                isTransitive = 0;
            }
        }
    }

    if (isTransitive)
    {
        return isTransitive;
    }
    else if (isAntitransitive)
    {
        return isAntitransitive;
    }
    else
    {
        return 2;
    }
}

void analyseRelation(int ** matrix, int size)
{
    printf("Your matrix is ");

    switch (isReflexive(matrix, size))
    {
        case 0: printf("antireflexive, "); break;
        case 1: printf("reflexive, "); break;
        case 2: printf("neither reflexive nor antireflexive, "); break;
    }

    switch (isSymmetric(matrix, size))
    {
        case 0: printf("antisymmetric, "); break;
        case 1: printf("symmetric, "); break;
        case 2: printf("neither symmetric nor antisymmetric, "); break;
    }

    switch (isTransitive(matrix, size))
    {
        case 0: printf("antitransitive, "); break;
        case 1: printf("transitive, "); break;
        case 2: printf("neither transitive nor antitransitive, "); break;
    }

    // is equivalent
    if (isReflexive(matrix, size) == 1 && isSymmetric(matrix, size) == 1 && isTransitive(matrix, size) == 1)
    {
        printf("equivalent, ");
    }
    else
    {
        printf("not equivalent, ");
    }

    // is order
    if (isSymmetric(matrix, size) == 0 && isTransitive(matrix, size) == 1)
    {
        printf("order, ");
    }
    else
    {
        printf("not order, ");
    }

    // is dependency
    if (isReflexive(matrix, size) == 1 && isSymmetric(matrix, size) == 1 && isTransitive(matrix, size) == 1)
    {
        printf("dependency.\n");
    }
    else
    {
        printf("not dependency.\n");
    }
}

void task1()
{
    int size1 = 0;
    printf("Enter matrix 1 size: ");
    scanf("%d", &size1);
    if (size1 < 1)
    {
        printf("Wrong size entered. Exit.\n");
        return 1;
    }
    
    // Array of pointers
    int ** matrix1 = (int**)malloc(size1 * sizeof(int*));

    if (NULL == matrix1)
    {
        printf("No memory left. Exit.\n");
        return 1;
    }

    // Each pointer to another array
    for (int i = 0; i < size1; i++)
    {
        matrix1[i] = (int*)malloc(size1 * sizeof(int));
        if (NULL == matrix1[i])
        {
            printf("No memory left. Exit.\n");
            return 1;
        }
    }

    // Entering matrix data
    printf("Enter matrix 1 data:\n");
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            scanf("%d", &matrix1[i][j]);
            if (matrix1[i][j] != 0 && matrix1[i][j] != 1)
            {
                printf("Wrong number entered. Should be 0 or 1. Exit.\n");
                return 1;
            }
        }
    }

    analyseRelation(matrix1, size1);

    // Free up space
    for (int i = 0; i < size1; i++)
    {
        if (matrix1[i])
        {
            free(matrix1[i]);
        }
    }
    free(matrix1);
    matrix1 = NULL;
}

int** findConverseRelation(int ** matrix, int size)
{
    // Array of pointers
    int ** result = (int**)malloc(size * sizeof(int*));

    if (NULL == result)
    {
        printf("No memory left. Exit.\n");
        return 1;
    }

    // Each pointer to another array
    for (int i = 0; i < size; i++)
    {
        result[i] = (int*)malloc(size * sizeof(int));
        if (NULL == result[i])
        {
            printf("No memory left. Exit.\n");
            return 1;
        }
    }

    // Entering matrix data
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

int** findComposition(int ** matrix1, int ** matrix2, int size)
{
    // Array of pointers
    int ** result = (int**)malloc(size * sizeof(int*));

    if (NULL == result)
    {
        printf("No memory left. Exit.\n");
        return 1;
    }

    // Each pointer to another array
    for (int i = 0; i < size; i++)
    {
        result[i] = (int*)malloc(size * sizeof(int));
        if (NULL == result[i])
        {
            printf("No memory left. Exit.\n");
            return 1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                if (matrix1[i][k] && matrix2[k][j])
                {
                    result[i][j] = 1;
                    break;
                }
            }
        }
    }

    return result;
}

void task2()
{
    int size2 = 0;
    printf("Enter matrix 2 and 3 size: ");
    scanf("%d", &size2);
    if (size2 < 1)
    {
        printf("Wrong size entered. Exit.\n");
        return 1;
    }
    
    // Array of pointers
    int ** matrix2 = (int**)malloc(size2 * sizeof(int*));
    int ** matrix3 = (int**)malloc(size2 * sizeof(int*));

    if (NULL == matrix2 || NULL == matrix3)
    {
        printf("No memory left. Exit.\n");
        return 1;
    }

    // Each pointer to another array
    for (int i = 0; i < size2; i++)
    {
        matrix2[i] = (int*)malloc(size2 * sizeof(int));
        matrix3[i] = (int*)malloc(size2 * sizeof(int));

        if (NULL == matrix2[i] || NULL == matrix3[i])
        {
            printf("No memory left. Exit.\n");
            return 1;
        }
    }

    // Entering matrix2 data
    printf("Enter matrix 2 data:\n");
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            scanf("%d", &matrix2[i][j]);
            if (matrix2[i][j] != 0 && matrix2[i][j] != 1)
            {
                printf("Wrong number entered. Should be 0 or 1. Exit.\n");
                return 1;
            }
        }
    }
    
    // Entering matrix3 data
    printf("Enter matrix 3 data:\n");
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            scanf("%d", &matrix3[i][j]);
            if (matrix3[i][j] != 0 && matrix3[i][j] != 1)
            {
                printf("Wrong number entered. Should be 0 or 1. Exit.\n");
                return 1;
            }
        }
    }

    int** converse2 = findConverseRelation(matrix2, size2);
    
    printf("Converse relation to matrix 2:\n");
    outputRelation(converse2, size2);

    // Free up space
    for (int i = 0; i < size2; i++)
    {
        if (converse2[i])
        {
            free(converse2[i]);
        }
    }
    free(converse2);
    converse2 = NULL;

    int** converse3 = findConverseRelation(matrix3, size2);

    printf("Converse relation to matrix 3:\n");
    outputRelation(converse3, size2);

    // Free up space
    for (int i = 0; i < size2; i++)
    {
        if (converse3[i])
        {
            free(converse3[i]);
        }
    }
    free(converse3);
    converse3 = NULL;
    
    int** composition23 = findComposition(matrix2, matrix3, size2);

    printf("Composition of matrix 2 and matrix 3:\n");
    outputRelation(composition23, size2);

    // Free up space
    for (int i = 0; i < size2; i++)
    {
        if (composition23[i])
        {
            free(composition23[i]);
        }
    }
    free(composition23);
    composition23 = NULL;

    int** composition32 = findComposition(matrix3, matrix2, size2);

    printf("Composition of matrix 3 and matrix 2:\n");
    outputRelation(composition32, size2);

    // Free up space
    for (int i = 0; i < size2; i++)
    {
        if (composition32[i])
        {
            free(composition32[i]);
        }
    }
    free(composition32);
    composition32 = NULL;

    // Free up space
    for (int i = 0; i < size2; i++)
    {
        if (matrix2[i])
        {
            free(matrix2[i]);
        }

        if (matrix3[i])
        {
            free(matrix3[i]);
        }
    }
    free(matrix2);
    matrix2 = NULL;
    free(matrix3);
    matrix3 = NULL;
}