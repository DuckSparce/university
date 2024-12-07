#include "support_functions.h"

double determinant(double matrix[2][2]) {
	return
		(matrix[0][0] * matrix[1][1]) -
		(matrix[1][0] * matrix[0][1]);
}

double determinant(double matrix[3][3]) {
	return 
		(matrix[0][0] * matrix[1][1] * matrix[2][2]) +
		(matrix[1][0] * matrix[2][1] * matrix[0][2]) +
		(matrix[0][1] * matrix[1][2] * matrix[2][0]) -
		(matrix[2][0] * matrix[1][1] * matrix[0][2]) -
		(matrix[1][0] * matrix[0][1] * matrix[2][2]) -
		(matrix[2][1] * matrix[1][2] * matrix[0][0]);
}

double isInvertible(double matrix[3][4]) {
	return
		((matrix[0][0] * matrix[1][1] * matrix[2][2]) +
		(matrix[1][0] * matrix[2][1] * matrix[0][2]) +
		(matrix[0][1] * matrix[1][2] * matrix[2][0]) -
		(matrix[2][0] * matrix[1][1] * matrix[0][2]) -
		(matrix[1][0] * matrix[0][1] * matrix[2][2]) -
		(matrix[2][1] * matrix[1][2] * matrix[0][0])) != 0;
}

bool inverse(double matrix[3][3], double result[3][3]) {
	double detA = determinant(matrix);

	if (!detA) {
		return false;
	}

	double tempMatrix[2][2];
	int row = 0;
	int col = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == k) {
					continue;
				}

				for (int l = 0; l < 3; l++) {
					if (j == l) {
						continue;
					}

					tempMatrix[row][col] = matrix[k][l];
					col++;
				}

				row++;
				col = 0;
			}

			result[j][i] = (((i + j) % 2) ? (-1) : (1)) * determinant(tempMatrix) / detA;

			row = 0;
			col = 0;
		}
	}

	return true;
}

bool swap(double matrix[3][4], unsigned int row1, unsigned int row2) {
	if (row1 > 3 || row2 > 3 || row1 == row2) {
		return false;
	}

	for (unsigned int i = 0; i < 4; i++) {
		const double temp = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = temp;
	}
}
