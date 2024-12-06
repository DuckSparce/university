#include <stdio.h>
#include <math.h>

int main()
{
	//task1();

	task2();
}

// Solve the arithmetical expression with one const z and two variables x, y.
int task1()
{
	const double z = 0.765;
	double x, y, b;
	printf("Enter x: ");
	scanf_s("%lf", &x);
	printf("Enter y: ");
	scanf_s("%lf", &y);

	b = pow(1 + pow(tan(z / 2), 2), sqrt(fabs(y) + x));
	printf("Result: % lf\n", b);

	return 0;
}

// Operate with the given number, so the result is a new number, made of the same digits reversed.
int task2()
{
	int initialNumber;
	int result = 0;
	printf("Enter an eight-digit number: ");
	scanf_s("%d", &initialNumber);

	if (initialNumber > 9999999 && initialNumber < 100000000) {
		int powerOfTen = 10000000;

	label:
		if (initialNumber != 0) {
			result += (initialNumber % 10) * powerOfTen;

			initialNumber /= 10;
			powerOfTen /= 10;

			goto label;
		}

		printf("Result: %d", result);
	}
	else {
		printf("Wrong number is entered.");
	}

	return 0;
}