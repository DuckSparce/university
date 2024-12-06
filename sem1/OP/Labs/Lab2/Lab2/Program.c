#include <stdio.h>
#include <math.h>

int main()
{

	return 0;
}

int task1()
{
	int iNum1 = 0;
	int iNum2 = 0;
	int isIncreasing = 1;

	printf("Enter positive integers to form the sequence.\n");

	while(1)
	{
		iNum2 = iNum1;
		scanf_s("%d", &iNum1);

		if (iNum1 == -1)
		{
			if (isIncreasing)
			{
				printf("The sequence is increasing.\n");
			}
			else
			{
				printf("The sequence is not increasing.\n");
			}
			break;
		}

		if (iNum1 < 1)
		{
			printf("Wrong number entered. Enter positive integer.\n");
			continue;
		}

		if (iNum1 <= iNum2)
		{
			isIncreasing = 0;
		}
	}

	return 0;
}

int task2()
{
	double a, b, step, eps;
	printf("Enter a between -1 and 1: ");
	scanf_s("%lf", &a);
	printf("Enter b between -1 and 1: ");
	scanf_s("%lf", &b);
	printf("Enter step: ");
	scanf_s("%lf", &step);
	printf("Enter eps: ");
	scanf_s("%lf", &eps);
	
	if (a > -1 && a < 1 && b > -1 && b < 1)
	{
		// a         real b     tailor b   diff
		// ...       ...        ...        ...
		printf("a\t\treal b\t\ttailor b\tdiff\n");
	
		for (double x = a; x <= b; x += step)
		{
			double real_y = pow(1 + x, -4);

			int i = 1;
			double x_i = 1.0;
			double sum = 1.0;

			while (fabs(x_i) > eps)
			{
				x_i *= (-x * (i + 3)) / i;
				sum += x_i;
				i++;
			}

			double tailor_y = sum;
			double diff = fabs(tailor_y - real_y);

			printf("%lf\t%lf\t%lf\t%lf\n", x, real_y, tailor_y, diff);
		}
	}
	else 
	{
		printf("Wrong value entered.\n");
	}

	return 0;
}