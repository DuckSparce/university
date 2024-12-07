#include <cstdio>
#include <iostream>
#include "io_functions.h"
#include "solving_functions.h"
#include "support_functions.h"

// The program is used to solve linear equations (matrix with n = 3)
int main() {
	bool source;
	std::cout << "Choose the source (0/false - console, 1/true - file): ";
	std::cin >> source;
	
	FILE * sourceFile = NULL;

	if (source) {
		char fileName[100];
		std::cout << "Enter file name: ";
		std::cin >> fileName;
		sourceFile = fopen(fileName, "r");
	} else {
		sourceFile = stdin;
	}

	double matrix[3][4] = { 0 };
	double results1[3] = { 0 };
	double results2[3] = { 0 };
	double results3[3] = { 0 };
	double results4[3] = { 0 };
	
	matrixInput(sourceFile, matrix);
	
	printf("\nGiven matrix:\n");
	matrixOutput(stdout, matrix);
	
	if (!isInvertible(matrix)) {
		printf("The matrix is degenerate/not invertible (Determinant = 0). No precise solution. Program exit.");
		return 1;
	}

	//cramersRule(matrix, results1);
	//matrixInverse(matrix, results2);
	gaussianElimination(matrix, results3);
	luDecomposition(matrix, results4);

	fclose(sourceFile);
}
