#include <stdio.h>
#include <math.h>

#define N 5

int main()
{
	// Алгоритми сортування
	int a[5];
	scanf_s("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

	// Bubble : about n*n iterations
	
	/*
	int temp = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++) 
		{
			if (a[j - 1] > a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;

				//a ^= b;
				//b ^= a;
				//a ^= b;
			}
		}
	}
	*/

	// Insertion : same as bubble
	
	/*
	int temp = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++) {
			if (a[j] > a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	*/

	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

	/*
	int a[5];
	scanf_s("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
	int max = a[0];

	for (int i = 1; i < 5; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	printf("from { %d, %d, %d, %d, %d } max is %d", a[0], a[1], a[2], a[3], a[4], max);
	*/

	/*
	//POINTERS

	//int a = 5;
	//int * b = &a;
	//printf("%d", *b);

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int b[] = { 1, 2, 3, 4, 5 };
	//// ...
	
	//int a[5][6];
	// &a[0][6] == &a[1][0]
	

	const int* a;
	int* const b;

	int a = 5;
	int* c = &a;

	c++;  // 5 -4- 3 2 1
	(*c)++; // 5 -5- 3 2 1


	int* const d = a;
	//d++;  // error
	(*d)++; // correct

	const int* e = a;
	e++;      // correct
	//(*e)++; // error

	const int* const f = a;
	//f++;    // error
	//(*f)++; // error

	//const int* = int const* вказівник на константу





	//int test;
	//scanf_s("%d", &test);

	//if ((test & 4) && (test & 16))
	//{
	//	printf("Yes");
	//}
	//else
	//{
	//	printf("No");
	//}	

	*/
}