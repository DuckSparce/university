#ifndef EQUATION_SYSTEM_H_
#define EQUATION_SYSTEM_H_

#include <cstdio>
#include <iostream>

#define SIZE 4

class EquationSystem {
public:
	EquationSystem();

	static double calculateMaxDifference(double X1[], double X2[]);

	bool in(FILE* source);
	bool out(FILE* destination);

	bool reset();

	bool jacobi(double eps);
	bool seidel(double eps);
	
	bool isConvergent();

private:
	double A[SIZE][SIZE];
	double B[SIZE];
	double X[SIZE];

	double alpha[SIZE][SIZE];
	double beta[SIZE];
};

#endif // EQUATION_SYSTEM_H_