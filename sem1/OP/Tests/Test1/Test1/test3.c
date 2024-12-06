#include <stdio.h>
#include <math.h>

int main()
{
	//solveEquation();

	//sort();

	test();
}
//документація до сканф і прінтф, як формується маска вводу/виводу

int test()
{
	int a = 1, b = 1;
	int aplus, plusb;
	aplus = a++;
	plusb = ++b;
	printf("a=%d aplus=%d\n", a, aplus);
	printf("b=%d plusb=%d\n", b, plusb);
	return 0;
}

int sort()
{
	int num;
	int i = 0;
	scanf_s("%d", &num);
	int max = num % 10;

mitka:

	if (num != 0)
	{
		if (num % 10 > max) 
		{
			max = num % 10;
		}
		printf("%d\n", num % 10);
		num /= 10;

		i++;
		goto mitka;
	}

	printf("Max is %d.\n", max);
}

int solveEquation()
{
	double a, b, c;
	printf("Enter your a.\n");
	scanf_s("%lf", &a);

	printf("Enter your b.\n");
	scanf_s("%lf", &b);

	printf("Enter your c.\n");
	scanf_s("%lf", &c);

	double d = b * b - 4 * a * c;


	if (a != 0)
	{
		if (d > 0)
		{
			double x1 = (-b - sqrt(d)) / (2 * a);
			double x2 = (-b + sqrt(d)) / (2 * a);

			printf("Results: %lf; %lf.\n", x1, x2);
		}
		else
		{
			if (d == 0)
			{
				double x = -b / (2 * a);
				printf("Result: %lf.\n", x);
			}
			else
			{
				printf("No real solution.\n");
			}
		}
	}
	else
	{
		printf("Not square equation.\n");
	}

	return 0;
}