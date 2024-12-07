#include <stdio.h>

#define MAXSIZE 15

void kruskal(int [MAXSIZE][MAXSIZE], int);

int main()
{
    // Size input
    int size = 0;
	printf("Enter matrix size (up to %d): ", MAXSIZE);
	scanf("%d", &size);
	if (size > MAXSIZE || size < 1)
    {
		printf("Wrong value entered. It should be positive and less than %d. End of program.", MAXSIZE);
		return 1;
	}

    // 0 12 6 20 14
    // 12 0 2 4 6
    // 6 2 0 10 12
    // 20 4 10 0 6
    // 14 6 12 6 0

    // Matrix input
    printf("Enter graph:\n");
	int matrix[MAXSIZE][MAXSIZE] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &matrix[i][j]);
			if ((matrix[i][j] < 0))
			{
				printf("Wrong number entered. It should be 0 or greater. End of program.");
				return 1;
			}
		}
	}

    kruskal(matrix, size);
}

void kruskal(int matrix[MAXSIZE][MAXSIZE], int size)
{
    // STEP 1
    int edges [MAXSIZE * (MAXSIZE - 1)][3] = {0};
    int edgesSize = size * (size - 1) / 2;
    for (int k = 0; k < edgesSize; k++)
	{
        int min = 1000;
        int minI = 0;
        int minJ = 1000;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (matrix[i][j] < min && matrix[i][j] > 0)
                {
                    min = matrix[i][j];
                    minI = i;
                    minJ = j;
                }
            }
        }
        edges[k][0] = minI;
        edges[k][1] = minJ;
        edges[k][2] = matrix[minI][minJ];
        matrix[minI][minJ] = 1000;
    }

    printf("Step1: {");
    for (int i = 0; i < edgesSize; i++)
    {
        printf(" %d,", edges[i][2]);
    }
    printf("\b }\n");

    int vertices[MAXSIZE] = {0};

    // STEP 2
    printf("Step2: {");
    for (int i = 0; i < size; i++)
    {
        printf( " {%d},", i + 1);
    }
    printf("\b }\n");

    // STEP 3-4
    int MST[MAXSIZE - 1][3] = {0};
    int temp = 0;
    for (int i = 0; i < edgesSize; i++)
    {
        if (vertices[edges[i][0]] != 1 && vertices[edges[i][1]] != 1)
        {
            MST[temp][1] = edges[i][1];
            MST[temp][2] = edges[i][2];
            MST[temp][3] = edges[i][3];
            vertices[edges[i][0]] = 1;
            vertices[edges[i][1]] = 1;
        }
    }

    printf("Step3-4:\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d-%d : %d\n", edges[i][0] + 1, edges[i][1] + 1, edges[i][2]);
    }
}