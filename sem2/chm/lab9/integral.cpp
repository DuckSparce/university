#include "integral.h"

#include <iostream>
#include <vector>

Integral::Integral(double a, double b, double eps)
	: m_a(a)
	, m_b(b)
	, m_eps(eps) {}

double Integral::leftEndpointRule(bool is_output, size_t * const n) const {
	double h = calculateStep(2);
	double current_x = m_a;
	double integral1 = 0.0;
	double integral2 = 0.0;
	
	while (current_x < m_b) {
		integral2 += FUNCTION(current_x) * h;
		current_x += h;
	}

	do {
		integral1 = integral2;
		integral2 = 0.0;
		current_x = m_a;
		h /= 2;

		while (current_x < m_b) {
			integral2 += FUNCTION(current_x) * h;
			current_x += h;
		}
	} while (fabs(integral1 - integral2) > m_eps);

	*n = static_cast<size_t>((m_b - m_a) / h);
	return integral2;
}

double Integral::rightEndpointRule(bool is_output, size_t* const n) const {
	double h = calculateStep(2);
	double current_x = m_b;
	double integral1 = 0.0;
	double integral2 = 0.0;

	while (current_x > m_a) {
		integral2 += FUNCTION(current_x) * h;
		current_x -= h;
	}

	do {
		integral1 = integral2;
		integral2 = 0.0;
		current_x = m_b;
		h /= 2;

		while (current_x > m_a) {
			integral2 += FUNCTION(current_x) * h;
			current_x -= h;
		}
	} while (fabs(integral1 - integral2) > m_eps);

	*n = static_cast<size_t>((m_b - m_a) / h);
	return integral2;
}

double Integral::midPointRule(bool is_output, size_t* const n) const {
	double h = calculateStep(2);
	double current_x = m_a + h / 2;
	double integral1 = 0.0;
	double integral2 = 0.0;

	while (current_x < m_b) {
		integral2 += FUNCTION(current_x) * h;
		current_x += h;
	}

	do {
		integral1 = integral2;
		integral2 = 0.0;
		h /= 2;
		current_x = m_a + h / 2;

		while (current_x < m_b) {
			integral2 += FUNCTION(current_x) * h;
			current_x += h;
		}
	} while (fabs(integral1 - integral2) > m_eps);

	*n = static_cast<size_t>((m_b - m_a) / h);
	return integral2;
}

double Integral::trapezoidalRule(bool is_output, size_t* const n) const {
	double h = calculateStep(2);
	double current_x = m_a;
	double integral1 = 0.0;
	double integral2 = 0.0;

	while (current_x < m_b) {
		integral2 += (FUNCTION(current_x) + FUNCTION(current_x + h)) / 2 * h;
		current_x += h;
	}

	do {
		integral1 = integral2;
		integral2 = 0.0;
		current_x = m_a;
		h /= 2;

		while (current_x < m_b) {
			integral2 += (FUNCTION(current_x) + FUNCTION(current_x + h)) / 2 * h;
			current_x += h;
		}
	} while (fabs(integral1 - integral2) > m_eps);

	*n = static_cast<size_t>((m_b - m_a) / h);
	return integral2;
}

double Integral::simpsonRule(bool is_output, size_t* const n) const {
	double h = calculateStep(4);
	double current_x = m_a;
	double integral1 = 0.0;
	double integral2 = 0.0;

	while (current_x < m_b) {
		integral2 += (FUNCTION(current_x) + FUNCTION(current_x + h) * 4 + FUNCTION(current_x + h * 2)) * h / 3;
		current_x += h * 2;
	}

	do {
		integral1 = integral2;
		integral2 = 0.0;
		current_x = m_a;
		h /= 2;

		while (current_x < m_b) {
			integral2 += (FUNCTION(current_x) + FUNCTION(current_x + h) * 4 + FUNCTION(current_x + h * 2)) * h / 3;
			current_x += h * 2;
		}
	} while (fabs(integral1 - integral2) > m_eps);

	*n = static_cast<size_t>((m_b - m_a) / h);
	return integral2;
}

double Integral::calculateStep(unsigned char num) const {
	if (num == 2) {
		unsigned int n = round((m_b - m_a) / pow(m_eps, 1.0 / num));
		return (m_b - m_a) / n + n % 2;
	} else if (num == 4) {
		return (m_b - m_a) / round((m_b - m_a) / pow(m_eps, 1.0 / num));
	} else {
		return NAN;
	}
}
