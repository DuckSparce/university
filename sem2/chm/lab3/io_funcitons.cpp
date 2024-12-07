#include <cstdio>
#include <iostream>
#include "io_functions.h"

bool matrixInput(FILE * source, double matrix[3][4]) {
	if (source == NULL) {
		return false;
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			fscanf(source, "%lf", &(matrix[i][j]));
		}
	}

	return true;
}

bool matrixOutput(FILE * destination, double matrix[3][4]) {
	if (destination == NULL) {
		return false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			fprintf(destination, "%g  ", matrix[i][j]);
		}

		fprintf(destination, "\n");
	}

	return true;
}

bool matrixOutput(FILE* destination, double matrix[3][3]) {
	if (destination == NULL) {
		return false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fprintf(destination, "%g  ", matrix[i][j]);
		}

		fprintf(destination, "\n");
	}

	return true;
}
