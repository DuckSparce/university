#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

#include "equation_system.h"

int main () {
	bool source;
	std::cout << "Choose the source (0/false - console, 1/true - file): ";
	std::cin >> source;

	FILE* sourceFile = nullptr;

	if (source) {
		char fileName[100];
		std::cout << "Enter file name: ";
		std::cin >> fileName;
		sourceFile = fopen(fileName, "r");
	} else {
		sourceFile = stdin;
	}

	EquationSystem system;
	system.in(sourceFile);

	double eps;
	std::cout << "Enter eps: ";
	std::cin >> eps;
	while (eps < 1e-10) {
		std::cout << "Wrong eps entered. Reenter the value. It must be greater than 1e-10.";
		std::cin >> eps;
	}

	if (!system.isConvergent()) {
		std::cout << "The system is not convergent. End of program.";
		exit(1);
	} else {
		std::cout << "\nThe system is convergent.\n";
	}

	system.jacobi(eps);
	system.seidel(eps);
}