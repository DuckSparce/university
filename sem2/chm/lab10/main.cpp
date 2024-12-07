#include "differential_equation.h"

#include <iostream>

int main() {
	std::cout << "The equation is: y' = x + cos(y / sqrt(0.3))\n";

	double x0, xn, y0, h;

	std::cout << "Enter x0: ";
	std::cin >> x0;
	std::cout << "Enter xn: ";
	std::cin >> xn;
	std::cout << "Enter y0: ";
	std::cin >> y0;
	std::cout << "Enter h (step): ";
	std::cin >> h;

	DifferentialEquation i(x0, xn, y0, h);

	std::cout << '\n';
	i.euler();
	std::cout << '\n';
	i.rungeKutta();
	std::cout << '\n';
	i.adams();

	return 0;
}