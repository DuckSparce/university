#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <vector>

class PolynomialApproximation {
public:
	PolynomialApproximation(size_t rank);

	void in(std::istream& source);
	void out(std::ostream& destination) const ;

	void reset(size_t new_rank);

	void approximate();

private:
	std::vector<double> m_x;
	std::vector<double> m_y;

	size_t m_rank;
	std::vector<double> m_coefficients;
};

#endif // POLYNOMIAL_H_