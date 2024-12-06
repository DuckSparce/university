#include <stdio.h>

#define N 3

// 1 2 4
// 3 5 7
// 6 8 9

void task1() {
	int matrix[N][N] = { 0 };
	int num = 1;

	int i = 0;
	int j = 0;

	// d - diagonal
	for (int d = 0; d < N; d++)	{
		i = 0;
		j = d;
		while (j >= 0) {
			matrix[i][j] = num;
			
			i++;
			j--;
			num++;
		}
	}

	for (int d = 1; d < N; d++)	{
		i = d;
		j = N - 1;

		while (i < N) {
			matrix[i][j] = num;

			i++;
			j--;
			num++;
		}
	}

	// Output
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void task2() {
	int matrix[N][N] = { 0 };
	int num = 1;

	int i = 0;
	int j = 0;

	int rightBorder = N;
	int bottomBorder = N;
	int leftBorder = -1;
	int topBorder = 0;
	
	while(rightBorder > leftBorder + 1) {
		while (j < rightBorder) {
			matrix[i][j++] = num++;
		}
		j--;
		i++;
		rightBorder--;

		while (i < bottomBorder) {
			matrix[i++][j] = num++;
		}
		i--;
		j--;
		bottomBorder--;

		while (j > leftBorder) {
			matrix[i][j--] = num++;
		}
		j++;
		i--;
		leftBorder++;

		while (i > topBorder) {
			matrix[i--][j] = num++;
		}
		i++;
		j++;
		topBorder++;
	}
	

	//Output
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	task1();
	printf("\n");
	task2();

	return 0;
}