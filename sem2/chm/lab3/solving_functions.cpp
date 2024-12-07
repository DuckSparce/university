#include <cstdio>
#include <cmath>

#include "io_functions.h"
#include "solving_functions.h"
#include "support_functions.h"

bool cramersRule(double matrix[3][4], double * X) {
	printf("\n=========== Cramer's rule ===========\n");

	double matrices[4][3][3];
	double determinants[4];

	printf("Matrix A:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrices[0][i][j] = matrix[i][j];
			printf("%g ", matrices[0][i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("Matrix A%d:\n", i + 1);
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				matrices[i + 1][j][k] = (k == i) ? matrix[j][3] : matrix[j][k];
				printf("%g ", matrices[i + 1][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		if (i) {
			printf("Determinant A%d:\n", i);
		} else {
			printf("Determinant A:\n");
		}

		determinants[i] = determinant(matrices[i]);
		printf("%g\n\n", determinants[i]);
	}

	for (int i = 0; i < 3; i++) {
		X[i] = determinants[i + 1] / determinants[0];
	}

	printf("Cramer's rule results: (%g, %g, %g)\n"
		"=====================================\n", X[0], X[1], X[2]);
	
	return true;
}

bool matrixInverse(double matrix[3][4], double * X) {
	printf("\n======= Inverse matrix method =======\n");
	
	double A[3][3];
	double B[3];
	// A * X = B
	// X = A^-1 * B

	printf("\nMatrix A:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] = matrix[i][j];
			printf("%g ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatrix B:\n");
	for (int i = 0; i < 3; i++) {
		B[i] = matrix[i][3];
		printf("%g\n", B[i]);
	}

	double invA[3][3];
	inverse(A, invA);
	printf("\nInverse matrix A^-1:\n");
	matrixOutput(stdout, invA);
	
	for (int i = 0; i < 3; i++) {
		X[i] = 0;
		for (int j = 0; j < 3; j++) {
			X[i] += invA[i][j] * B[j];
		}
	}
	
	printf("\nInverse matrix method results: (%g, %g, %g)\n"
		"=====================================\n", X[0], X[1], X[2]);

	return true;
}

bool gaussianElimination(double m[3][4], double* X) {
	printf("\n==== Gaussian elimination method ====\n");

	double matrix[3][4] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = m[i][j];
		}
	}

	// . . . | .      . . . | .      . . . | .
	// 0 . . | .  ->  0 . . | .  ->  0 . . | .
	// . . . | .      0 . . | .      0 0 . | .
	
	for (int i = 0; i < 2; i++) {
		matrixOutput(stdout, matrix);
		printf("\n");

		// Find the main row
		double max = abs(matrix[i][i]);
		unsigned int maxRow = i;
		for (int j = i + 1; j < 3; j++) {
			if (abs(matrix[j][i]) > max) {
				max = abs(matrix[j][i]);
				maxRow = j;
			}
		}	
		swap(matrix, i, maxRow);

		for (int j = i + 1; j < 3; j++) {
			const double multiplier = matrix[j][i] / matrix[i][i];
			for (int k = 0; k < 4; k++) {
				matrix[j][k] -= matrix[i][k] * multiplier;
			}
		}

		matrixOutput(stdout, matrix);
		printf("\n");
	}
	
	for (int i = 2; i >= 0; i--) {
		X[i] = matrix[i][3] / matrix[i][i];
		for (int j = i - 1; j >= 0; j--) {
			matrix[j][3] -= matrix[j][i] * X[i];
			matrix[j][i] = 0;
		}
	}

	printf("\nGaussian elimination method results: (%g, %g, %g)\n"
		"=====================================\n", X[0], X[1], X[2]);

	return true;
}

bool luDecomposition(double matrix[3][4], double* X) {
	printf("\n====== LU Decomposition method ======\n");

	double b[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		b[i] = matrix[i][3];
	}

	double l[3][3] = { { 0 } };
	double u[3][3] = { { 0 } };

	for (int k = 0; k < 3; k++) {
		u[k][k] = 1;
		for (int i = k; i < 3; i++) {
			for (int j = k + 1; j <= 3; j++) {
				double sum = 0;
				for (int m = 0; m < k; m++) {
					sum += l[i][m] * u[m][k];
				}
				l[i][k] = matrix[i][k] - sum;

				sum = 0;
				for (int m = 0; m < k; m++) {
					sum += l[k][m] * u[m][j];
				}
				
				if (j != 3) {
					u[k][j] = 1 / l[k][k] * (matrix[k][j] - sum);
				}
			}
		}

		printf("\nStep %d:\nL:\n", k + 1);
		matrixOutput(stdout, l);
		printf("U:\n");
		matrixOutput(stdout, u);
	}
	
	double y[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		y[i] = b[i] / l[i][i];
		
		for (int j = i + 1; j < 3; j++) {
			b[j] -= l[j][i] * y[i];
		}
	}

	printf("\nLY = B\nY = (%g, %g, %g)\n", y[0], y[1], y[2]);

	for (int i = 2; i >= 0; i--) {
		X[i] = y[i];
		for (int j = i - 1; j >= 0; j--) {
			y[j] -= u[j][i] * X[i];
		}
	}

	printf("\nUX = Y, where X - results.\n");
	printf("\nLU Decomposition method results: (%g, %g, %g)\n"
		"=====================================\n", X[0], X[1], X[2]);

	return true;
}
