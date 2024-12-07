#include "polynomial.h"

Polynomial::Polynomial()
	: m_x0(0)
	, m_y0(0) {
	for (int i = 0; i < N; i++) {
		m_coefficients[i] = 0;
		m_x[i] = 0;
		m_y[i] = 0;
	}
}

void Polynomial::in(FILE* source){
	fscanf(source, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		&m_x[0], &m_x[1], &m_x[2], &m_x[3], &m_x[4], &m_x[5], &m_x[6], &m_x[7], &m_x[8], &m_x[9]);
	fscanf(source, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		&m_y[0], &m_y[1], &m_y[2], &m_y[3], &m_y[4], &m_y[5], &m_y[6], &m_y[7], &m_y[8], &m_y[9]);
	fscanf(source, "%lf", &m_x0);
}

void Polynomial::restart() {
	m_y0 = 0;
	for (int i = 0; i < N; i++) {
		m_coefficients[i] = 0;
	}
}

double Polynomial::lagrange() {
	printf("LAGRANGE START\n");

	for (int i = 0; i < N; i++) {
		double l = 1;

		for (int j = 0; j < N; j++) {
			if (i != j) {
				l *= m_x0 - m_x[j];
				l /= m_x[i] - m_x[j];
			}
		}

		m_y0 += l * m_y[i];
	}

	printf("In the x = %lf the function value is %lf.\n", m_x0, m_y0);
	printf("LAGRANGE END\n\n");

	return m_y0;
}

// For equally arranged points
double Polynomial::newton() {
	printf("NEWTON END\n");

	double h = m_x[1] - m_x[0];
	m_y0 = m_y[0];

	double deltas[N][N] = { 0 };

	for (int i = 0; i < N; i++) {
		deltas[i][0] = m_y[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			deltas[j][i] = deltas[j + 1][i - 1] - deltas[j][i - 1];
		}
	}

	for (int i = 1; i < N; i++) {
		double numerator = deltas[0][i];
		double denominator = tgamma(i + 1);
		double term = 0;

		for (int j = 0; j < i; j++) {
			numerator *= m_x0 - m_x[j];
			denominator *= h;
		}

		term = numerator / denominator;
		m_y0 += term;
	}

	printf("In the x = %lf the function value is %lf.\n", m_x0, m_y0);
	printf("NEWTON END\n");


	return m_y0;
}