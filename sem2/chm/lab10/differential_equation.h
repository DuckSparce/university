#ifndef DIFFERENTIAL_EQUATION_H
#define DIFFERENTIAL_EQUATION_H

class DifferentialEquation {
public:
	DifferentialEquation(double x0, double xn, double y0, double h);

	void euler();

	void rungeKutta();

	void adams();

private:
	// Function in format dy/dx = f(x, y)
	double function(double x, double y);

	double m_x0;
	double m_xn;
	double m_y0;
	double m_h;
};

#endif // DIFFERENTIAL_EQUATION_H