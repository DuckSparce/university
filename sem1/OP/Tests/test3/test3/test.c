#include <stdio.h>
#include <math.h>

int main()
{
	int x = 13;
	int y = 24;
	printf("%d", x | y);

	// побітовий зсув
	// >>
	// <<
	//
	// інверсія
	// ~
	// 
	//5 << 1 = 10
	//
	// x = 1101
	// res needed = 1001
	//x = s & (~(1<<2)) = 1001

	//y = x = 5; // allowed
	
}

int triangle()
{
	int x = 0;
	scanf_s("%d", &x);
	for (int i = x; i > 0; i -= 2)
	{
		for (int j = 0; j < i / 2; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < x - i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int test1() 
{
	int i = 0;
	//ВИДИ ЦИКЛІВ

	//1. З передумовою
	while (i = 0)
	{

	}
	while (1) {}

	//2. З післядумовою
	do
	{

	} while (i = 0);

	//3. З параметром
	for (int a = 1; i > 1; i++)
	{

	}
	for (;;) {}

	return 0;
}