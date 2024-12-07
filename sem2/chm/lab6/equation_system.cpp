#include <iostream>
#include <cmath>

#include "equation_system.h"

double EquationSystem::calculateMaxDifference(double X1[2], double X2[2]) {
	double result = abs(X1[0] - X2[0]);

	for (int i = 1; i < 2; i++) {
		const double current = abs(X1[i] - X2[i]);

		if (current > result) {
			result = current;
		}
	}

	return result;
}

bool EquationSystem::reset() {
	X[0] = 0;
	X[1] = 0;

	return true;
}

bool EquationSystem::iteration(const double eps) {
	reset();

	double tempX[2];
	int step = 0; //iteration

	std::cout << "\nITERATION START\n\n";
	// Initial approximation is 0
	for (int i = 0; i < 2; i++) {
		tempX[i] = 1;
	}

	// Actual algorithm
	do {
		// Output
		std::cout << "Step " << step << "\t| ";
		for (int i = 0; i < 2; i++) {
			X[i] = tempX[i];
			std::cout << X[i] << "\t| ";
		}
		std::cout << "\n";

		tempX[0] = PHI1(X[0], X[1]);
		tempX[1] = PHI2(X[0], X[1]);

		step++;
	} while (calculateMaxDifference(X, tempX) >= eps);

	// Output
	std::cout << "Step " << step << "\t| ";
	for (int i = 0; i < 2; i++) {
		X[i] = tempX[i];
		std::cout << X[i] << "\t| ";
	}
	std::cout << "\n";

	std::cout << "\nITERATION END\n";

	return true;
}

bool EquationSystem::newton(const double eps) {
	reset();

	double tempX[2];
	int step = 0; //iteration

	std::cout << "\nNEWTON START\n\n";
	// Initial approximation
	for (int i = 0; i < 2; i++) {
		tempX[i] = 1;
	}

	// Actual algorithm
	do {
		// Output
		std::cout << "Step " << step << "\t| ";
		for (int i = 0; i < 2; i++) {
			X[i] = tempX[i];
			std::cout << X[i] << "\t| ";
		}
		std::cout << "\n";

		const double delta = (2 * 1) - (-sin(tempX[0] - 1) * cos(tempX[1]));
		const double deltaX = -1 / delta * ((sin(tempX[1]) + 2 * tempX[0] - 2) * 1 - (cos(tempX[0] - 1) + tempX[1] - 0.7) * cos(tempX[1]));
		const double deltaY = -1 / delta * (2 * (cos(tempX[0] - 1) + tempX[1] - 0.7) - (-sin(tempX[0] - 1) * (sin(tempX[1]) + 2 * tempX[0] - 2)));

		tempX[0] = X[0] + deltaX;
		tempX[1] = X[1] + deltaY;

		step++;
	} while (calculateMaxDifference(X, tempX) >= eps);

	// Output
	std::cout << "Step " << step << "\t| ";
	for (int i = 0; i < 2; i++) {
		X[i] = tempX[i];
		std::cout << X[i] << "\t| ";
	}
	std::cout << "\n";

	std::cout << "\nNEWTON END\n";

	return true;
}
