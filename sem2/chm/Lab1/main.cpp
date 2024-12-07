#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "root_finding_algorithms.h"

int main() {
	double a = 0;
	double b = 0;
	double eps = 0;
	
	printf("Enter a (first point of interval): ");
	scanf("%lf", &a);
	printf("Enter a (first point of interval): ");
	scanf("%lf", &b);
	printf("Enter eps (accuracy): ");
	scanf("%lf", &eps);
	
	if (!isIntervalCorrect(a, b, eps)) {
		printf("Wrong [a, b] interval passed. End of program.\n");
		return 1;
	}

	dichotomy(a, b, eps);
	interpolation(a, b, eps);
	tangent(a, b, eps);
	iteration(a, b, eps);
}