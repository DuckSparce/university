#include <stdio.h>

#define N 10

int main()
{
	int matrix[N][N] = { 0 };
	int n = 0;
	printf("Enter matrix size n: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Enter element(%d, %d): ", i + 1, j + 1);
			scanf_s("%d", &matrix[i][j]);
		}
	}

	printf("Your matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	//rows
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = matrix[0][i];
		matrix[0][i] = matrix[n - 1][i];
		matrix[n - 1][i] = temp;
	}

	printf("Changed rows:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	//columns
	for (int i = 0; i < n; i++)
	{
		temp = matrix[i][0];
		matrix[i][0] = matrix[i][n - 1];
		matrix[i][n - 1] = temp;
	}

	printf("Changed columns:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	int imin = 0;
	int jmin = 0;
	int imax = 0;
	int jmax = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] < matrix[imin][jmin])
			{
				jmin = j;
				imin = i;
				continue;
			}
			if (matrix[i][j] > matrix[imax][jmax])
			{
				jmax = j;
				imax = i;
			}
		}
	}

	temp = matrix[imin][jmin];
	matrix[imin][jmin] = matrix[imax][jmax];
	matrix[imax][jmax] = temp;

	printf("Result:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Max: %d\n", matrix[imin][jmin]);
	printf("Min: %d", matrix[imax][jmax]);

	return 0;
}