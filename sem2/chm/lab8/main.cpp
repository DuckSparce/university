#include "polynomial_approximation.h"

#include <fstream>
#include <iostream>
#include <string>

int main() {
	bool is_file;

	std::cout << "Choose the source (0/false - console, 1/true - file): ";
	std::cin >> is_file;

	PolynomialApproximation pa(1);

	if (is_file) {
		std::string file_name;
		std::cout << "Enter file name: ";
		std::cin >> file_name;
		std::ifstream source(file_name);
		pa.in(source);
		source.close();
	} else {	
		pa.in(std::cin);	
	}

	pa.approximate();
	pa.out(std::cout);
	pa.reset(2);
	pa.approximate();
	pa.out(std::cout);
	pa.reset(3);
	pa.approximate();
	pa.out(std::cout);
}