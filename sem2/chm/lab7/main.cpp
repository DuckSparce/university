#include <iostream>

#include "polynomial.h"

int main() {
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

	Polynomial polynomial;
	polynomial.in(sourceFile);
	if (source) fclose(sourceFile);

	polynomial.lagrange();
	polynomial.restart();
	polynomial.newton();

	// The answer is 4.605
}
