#include <iostream>

#include "integral.h"

int main() {
	double a, b, eps;

	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter eps: ";
	std::cin >> eps;

	Integral i(a, b, eps);
	size_t n = 0;

	std::cout << "\nLeft Endpoint rule result: " << i.leftEndpointRule(true, &n) << ". N = " << n << ".\n\n";
	
	std::cout << "Right Endpoint rule result: " << i.rightEndpointRule(true, &n) << ". N = " << n << ".\n\n";

	std::cout << "Mid-point rule result: " << i.midPointRule(true, &n) << ". N = " << n << ".\n\n";
	
	std::cout << "Trapezoidal rule result: " << i.trapezoidalRule(true, &n) << ". N = " << n << ".\n\n";

	std::cout << "Simpson's rule result: " << i.simpsonRule(true, &n) << ". N = " << n << ".\n";
	
	return 0;
}