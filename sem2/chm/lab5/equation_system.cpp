#include "equation_system.h"

EquationSystem::EquationSystem() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			A[i][j] = 0;
		}
		X[i] = B[i] = 0;
	}
}

double EquationSystem::calculateMaxDifference(double X1[SIZE], double X2[SIZE]) {
	double result = abs(X1[0] - X2[0]);

	for (int i = 1; i < SIZE; i++) {
		const double current = abs(X1[i] - X2[i]);

		if (current > result) {
			result = current;
		}
	}

	return result;
}

bool EquationSystem::in(FILE* source) {
	if (source == nullptr) {
		return false;
	}

	// Fill A and B matrices
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			fscanf_s(source, "%lf", &A[i][j]);
		}

		fscanf_s(source, "%lf", &B[i]);
	}

	// Nullify X vecor
	reset();

	// Calculate alpha and beta matrices
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (j != i) {
				alpha[i][j] = -A[i][j] / A[i][i];
			} else {
				alpha[i][j] = 0;
			}
		}

		beta[i] = B[i] / A[i][i];
	}

	return true;
}

bool EquationSystem::reset() {
	for (int i = 0; i < SIZE; i++) {
		X[i] = 0;
	}

	return true;
}

bool EquationSystem::jacobi(const double eps) {
	reset();

	double tempX[SIZE];
	int step = 0; //iteration

	std::cout << "\nJACOBI START\n\n";
	// Initial approximation is beta
	for (int i = 0; i < SIZE; i++) {
		tempX[i] = beta[i]; // 8 iterations
		//tempX[i] = 0; // 9 iterations
		//tempX[i] = 1; // 9 iterations
	}

	// Actual algorithm
	while (calculateMaxDifference(X, tempX) >= eps) {
		// Output
		std::cout << "Step " << step << "\t| ";
		for (int i = 0; i < SIZE; i++) {
			X[i] = tempX[i];
			std::cout << X[i] << "\t| ";
		}
		std::cout << "\n";

		for (int i = 0; i < SIZE; i++) {
			tempX[i] = beta[i];

			for (int j = 0; j < SIZE; j++) {
				if (i == j) {
					continue;
				}

				tempX[i] += alpha[i][j] * X[j];
			}
		}

		step++;
	}

	// Output
	std::cout << "Step " << step << "\t| ";
	for (int i = 0; i < SIZE; i++) {
		X[i] = tempX[i];
		std::cout << X[i] << "\t| ";
	}
	std::cout << "\n";

	std::cout << "\nJACOBI END\n";

	return true;
}

bool EquationSystem::seidel(const double eps) {
	reset();

	double tempX[SIZE];
	int step = 0; //iteration

	std::cout << "\nSEIDEL START\n\n";
	// Initial approximation is beta
	for (int i = 0; i < SIZE; i++) {
		tempX[i] = beta[i]; // 8 iterations
		//tempX[i] = 0; // 9 iterations
		//tempX[i] = 1; // 9 iterations
	}

	// Actual algorithm
	while (calculateMaxDifference(X, tempX) >= eps) {
		// Output
		std::cout << "Step " << step << "\t| ";
		for (int i = 0; i < SIZE; i++) {
			X[i] = tempX[i];
			std::cout << X[i] << "\t| ";
		}
		std::cout << "\n";

		for (int i = 0; i < SIZE; i++) {
			tempX[i] = beta[i];

			for (int j = 0; j < SIZE; j++) {
				if (i == j) {
					continue;
				}

				tempX[i] += alpha[i][j] * (j > i ? X[j] : tempX[j]);
			}
		}

		step++;
	}

	// Output
	std::cout << "Step " << step << "\t| ";
	for (int i = 0; i < SIZE; i++) {
		X[i] = tempX[i];
		std::cout << X[i] << "\t| ";
	}
	std::cout << "\n";

	std::cout << "\nSEIDEL END\n";

	return true;
}

bool EquationSystem::isConvergent() {
	double max = 0;

	for (int i = 0; i < SIZE; i++) {
		double sum = 0;

		for (int j = 0; j < SIZE; j++) {
			sum += alpha[i][j];
		}

		if (sum > max) {
			max = sum;
		}
	}

	if (max < 1) {
		return true;
	}

	return false;
}
