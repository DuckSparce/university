#include <cstdio>
#include <cmath>
#include "root_finding_algorithms.h"

#define FUNCTION(X) ((X) * (X) * (X) + 5 * (X) * (X) + 2 * (X) - 14)
#define FIRST_DERIVATIVE(X) (3 * (X) * (X) + 10 * (X) + 2)
#define SECOND_DERIVATIVE(X) (6 * (X) + 10)
#define CANONICAL_FORM(X) 14 / ((X) * (X) + 5 * (X) + 2)

bool isIntervalCorrect(double a, double b, double eps) {
	return !(FUNCTION(a) * FUNCTION(b) > 0 || isnan(a) || isnan(b) || isinf(a) || isinf(b));
}

// 1. Dichotomy/Bisection method
double dichotomy(double a, double b, double eps) {
	if (isIntervalCorrect(a, b, eps)) {
		// if f(a) is positive, a and b is swapped considering that f(a) must be negative and f(b) must be positive.
		if (FUNCTION(a) > 0) {
			double temp = a;
			a = b;
			b = temp;
		}

		int n = 0;
		double x = (a + b) / 2;

		while (true) {
			if (abs(a - b) > eps) {
				if (FUNCTION(x) < 0) {
					a = x;
				} else {
					b = x;
				}
			} else {
				printf("Dichotomy/Bisection algorithm took %d iterations. Returned approximate result is %lf.\n", n, x);
				return x;
			}
			x = (a + b) / 2;
			n++;
		}
	}

	return NAN;
}

// 2. Interpolation/Chord method
double interpolation(double a, double b, double eps) {
	if (isIntervalCorrect(a, b, eps)) {
		// Calculating which point is moving and of a chord and which is static
		if (FUNCTION(a) * SECOND_DERIVATIVE(a) > 0) {
			double temp = a;
			a = b;
			b = temp;
		}

		int n = 0;
		double x = b - (FUNCTION(b) * (b - a)) / (FUNCTION(b) - FUNCTION(a));

		while (true) {
			if (abs(x - b) > eps) {
				b = x;
			} else {
				printf("Interpolation/Chord algorithm took %d iterations. Returned approximate result is %lf.\n", n, x);
				return x;
			}
			x = b - (FUNCTION(b) * (b - a)) / (FUNCTION(b) - FUNCTION(a));
			n++;
		}
	}
		
	return NAN;
}

// 3. Newton/Tangent method
double tangent(double a, double b, double eps) {
	if (isIntervalCorrect(a, b, eps)) {
		// Finding out which point is start: a or b
		if (FUNCTION(b) * SECOND_DERIVATIVE(b) > 0) {
			double temp = a;
			a = b;
			b = temp;
		}

		int n = 0;
		double x = b - (FUNCTION(b) / FIRST_DERIVATIVE(b));

		while (true) {
			if (abs(x - b) > eps) {
				b = x;
			} else {
				printf("Newton/Tangent algorithm took %d iterations. Returned approximate result is %lf.\n", n, x);
				return x;
			}
			x = b - (FUNCTION(b) / FIRST_DERIVATIVE(b));
			n++;
		}
	}

	return NAN;
}

// 4. Fixed point iteration method
double iteration(double a, double b, double eps) {
	if (isIntervalCorrect(a, b, eps)) {
		int n = 0;
		double x = CANONICAL_FORM(b);

		while (true) {
			if (abs(x - b) > eps) {
				b = x;
			} else {
				printf("Fixed point iteration algorithm took %d iterations. Returned approximate result is %lf.\n", n, x);
				return x;
			}
			x = CANONICAL_FORM(b);
			n++;
		}
	}

	return NAN;
}