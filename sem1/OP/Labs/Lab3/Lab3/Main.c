#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3		// should be integer > 0
#define ROWS 4		// should be integer > 1
#define COLUMNS 3	// should be integer > 0

int main()
{
	printf("TASK1.\n");
	task1();

	printf("\nTASK2.\n");
	task2();
}

int task1()
{
	double arr[SIZE] = { 0 };
	int maxIndex = 0;
	double average = 0;
	
	for (int i = 0; i < SIZE; i++) 
	{
		printf("Enter a value: ");
		scanf("%lf", &arr[i]);
	
		average += *(arr+i);
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	average /= SIZE;
	printf("Average: %g\n", average);

	for (int i = maxIndex + 1; i < SIZE; i++)
	{
		arr[i] += average;
	}

	printf("Result array: {");
	for (int i = 0; i < SIZE; i++)
	{
		printf(" %g,", *(arr + i));
	}
	printf("\b }");

	return 0;
}

int task2()
{
	double matrix[ROWS][COLUMNS] = { 0 };

	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		printf("Enter a value: ");
		scanf("%lf", *matrix + i);
	}

	for (int i = 0; i < ROWS - 2; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			matrix[i][j] = (*(matrix + i + 2))[j];
		}
	}

	for (int i = ROWS - 2; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			*(*(matrix + i) + j) = 0;
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			printf("%g\t", *(matrix[i] + j));
		}
		printf("\n");
	}

	return 0;
}