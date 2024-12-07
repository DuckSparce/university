#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

#include "equation_system.h"

int main() {
	EquationSystem system;
	double eps;
	std::cout << "Enter eps: ";
	std::cin >> eps;
	while (eps < 1e-10) {
		std::cout << "Wrong eps entered. Reenter the value. It must be greater than 1e-10.";
		std::cin >> eps;
	}

	system.iteration(eps);
	system.newton(eps);
}