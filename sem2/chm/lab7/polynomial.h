#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define N 10
#include <iostream>
#include <cstdio>
#include <cmath>

class Polynomial {
public:
	Polynomial();

	void in(FILE* file);

	double lagrange();
	double newton();

	void restart();

private:
	double m_x[N];
	double m_y[N];

	double m_x0;
	double m_y0;

	double m_coefficients[N];
};

#endif // POLYNOMIAL_H