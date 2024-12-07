#ifndef INTEGRAL_H_
#define INTEGRAL_H_

#include <cmath>

#define FUNCTION(X) ((sinh(X) + sin(X) / 2) / (log10(1 - (X))))

class Integral {
public:
	Integral(double a, double b, double eps);
	
	double leftEndpointRule(bool is_output, size_t * const n) const;
	double rightEndpointRule(bool is_output, size_t * const n) const;
	double midPointRule(bool is_output, size_t * const n) const;

	double trapezoidalRule(bool is_output, size_t * const n) const;

	double simpsonRule(bool is_output, size_t * const n) const;

private:
	double calculateStep(unsigned char num) const;

	double m_a;
	double m_b;
	double m_eps;
};

#endif // INTEGRAL_H_
