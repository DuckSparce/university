#include "differential_equation.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

DifferentialEquation::DifferentialEquation(double x0, double xn, double y0, double h)
	: m_x0(x0)
	, m_xn(xn)
	, m_y0(y0)
	, m_h(h) {}

void DifferentialEquation::euler() {
	std::vector<double> x_values, y_values;
    double x = m_x0;
    double y = m_y0;
    int steps = 0;

    x_values.push_back(x);
    y_values.push_back(y);

    while (x < m_xn) {
        y += m_h * function(x, y);
        x += m_h;

        x_values.push_back(x);
        y_values.push_back(y);
        steps++;
    }

    std::cout << "Euler's Method Solution:" << '\n';
	std::cout << "i" << '\t' << "x" << '\t' << "y" << '\n';

    for (int i = 0; i <= steps; i++) {
	    std::cout << i << '\t' << x_values[i] << '\t' << y_values[i] << '\n';
    }
}

void DifferentialEquation::rungeKutta() {
	std::vector<double> x_values, y_values;
    double x = m_x0;
    double y = m_y0;
    int steps = 0;

    x_values.push_back(x);
    y_values.push_back(y);

    // Perform Runge-Kutta method
    while (x < m_xn) {
        double k1 = m_h * function(x, y);
        double k2 = m_h * function(x + m_h / 2, y + k1 / 2);
        double k3 = m_h * function(x + m_h / 2, y + k2 / 2);
        double k4 = m_h * function(x + m_h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += m_h;

        // Add values to the table
        x_values.push_back(x);
        y_values.push_back(y);
        steps++;
    }

    std::cout << "Runge-Kutta Method Solution:" << '\n';
    std::cout << "i" << '\t' << "x" << '\t' << "y" << '\n';

    for (int i = 0; i <= steps; i++) {
        std::cout << i << '\t' << x_values[i] << '\t' << y_values[i] << '\n';
    }
}

void DifferentialEquation::adams() {
	std::vector<double> x_values;
	std::vector<double> y_values;
	double x = m_x0;
    double y = m_y0;
    int steps = 0;

    x_values.push_back(x);
    y_values.push_back(y);

    // Find y1, y2, y3 first (via Runge-Kutta)
    for (int i = 1; i < 4; i++) {
        double k1 = m_h * function(x, y);
        double k2 = m_h * function(x + m_h / 2, y + k1 / 2);
        double k3 = m_h * function(x + m_h / 2, y + k2 / 2);
        double k4 = m_h * function(x + m_h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += m_h;

        x_values.push_back(x);
        y_values.push_back(y);
        steps++;
    }

    for (int i = 3; x < m_xn; i++) {
        double predicted_y = y_values[i] + 1.0/24 * m_h *
            (55 * y_values[i] - 59 * y_values[i - 1] + 37 * y_values[i - 2] - 9 * y_values[i - 3]);
        double corrected_y = y_values[i] + 1.0 / 24 * m_h *
            (9 * predicted_y + 19 * y_values[i] - 5 * y_values[i - 1] + y_values[i - 2]);
        
        while (fabs(predicted_y - corrected_y) > m_h / 10) {
            predicted_y = corrected_y;
			double corrected_y = y_values[i] + 1.0 / 24 * m_h *
				(9 * predicted_y + 19 * y_values[i] - 5 * y_values[i - 1] + y_values[i - 2]);
        }
        
        y = corrected_y;
        x += m_h;

        // Add values to the table
        x_values.push_back(x);
        y_values.push_back(y);
        steps++;
    }

    std::cout << "Adams' Method Solution:" << '\n';
    std::cout << "i" << '\t' << "x" << '\t' << "y" << '\n';

    for (int i = 0; i <= steps; i++) {
        std::cout << i << '\t' << x_values[i] << '\t' << y_values[i] << '\n';
    }
}

double DifferentialEquation::function(double x, double y) {
	return x + cos(y / sqrt(0.3));
}