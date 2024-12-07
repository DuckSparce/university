#include "polynomial_approximation.h"

PolynomialApproximation::PolynomialApproximation(size_t rank)
	: m_rank(rank) {
	m_x.clear();
	m_y.clear();
	m_coefficients.clear();
	m_coefficients.resize(m_rank + 1);
}

void PolynomialApproximation::in(std::istream& source) {
	size_t n = 0;
	source >> n;
	m_x.resize(n);
	m_y.resize(n);

	double temp = 0;

	for (size_t i = 0; i < n; i++) {
		source >> m_x[i];
	}

	for (size_t i = 0; i < n; i++) {
		source >> m_y[i];
	}
}

void PolynomialApproximation::out(std::ostream& destination) const {
	destination << "P(" << m_rank << ") = " << (m_coefficients[0] < 0 ? "- " : "") << fabs(m_coefficients[0]);

	for (size_t i = 1; i <= m_rank; i++) {
		std::cout << (m_coefficients[i] < 0 ? " - " : " + ") << fabs(m_coefficients[i]) << "*x^" << i;
	}

	destination << '\n';
}

void PolynomialApproximation::reset(size_t new_rank) {
	m_rank = new_rank;
	m_coefficients.clear();
	m_coefficients.resize(m_rank + 1);
}

void PolynomialApproximation::approximate() {
	const size_t n = m_x.size();

	if (m_rank > n) {
		std::cerr << "Polynomial rank (" << m_rank << ") can't be higher than number of given points" << n << ".\n";
		return;
	}

	const size_t system_size = m_rank + 1;
	std::vector<std::vector<double>> system(system_size);

	// Create a system AX = B
	// X = {a0, a1, ...}
	for (size_t i = 0; i < system_size; i++) {
		// Matrix A
		system[i].resize(system_size + 1);
		for (size_t j = 0; j < system_size; j++) {
			system[i][j] = 0;
			for (size_t k = 0; k < n; k++) {
				system[i][j] += pow(m_x[k], i + j);
			}
		}

		// Vector B
		system[i][system_size] = 0;
		for (size_t k = 0; k < n; k++) {
			system[i][system_size] += m_y[k] * pow(m_x[k], i);
		}
	}

	// Solve the system using Gaussian elimination
	// Onwards
	for (size_t i = 0; i < system_size - 1; i++) {
		for (size_t j = i + 1; j < system_size; j++) {
			const double multiplier = system[j][i] / system[i][i];
			for (size_t k = 0; k < system_size + 1; k++) {
				system[j][k] -= system[i][k] * multiplier;
			}
		}
	}

	// Backwards
	for (size_t i = system_size - 1; i < system_size; i--) {
		m_coefficients[i] = system[i][system_size] / system[i][i];
		for (size_t j = i - 1; j < i; j--) {
			system[j][system_size] -= system[j][i] * m_coefficients[i];
			system[j][i] = 0;
		}
	}
}
