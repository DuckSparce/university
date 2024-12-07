#ifndef EQUATION_SYSTEM_H_
#define EQUATION_SYSTEM_H_

#define F1(X, Y) sin(Y) + 2 * X - 2
#define F2(X, Y) cos(X - 1) + Y - 0.7

// For iteration method
#define PHI1(X, Y) ((2 - sin(Y)) / 2)
#define PHI2(X, Y) (0.7 - cos((X) - 1))

class EquationSystem {
public:
	EquationSystem() = default;

	static double calculateMaxDifference(double X1[], double X2[]);

	bool reset();

	bool iteration(double eps);
	bool newton(double eps);

private:
	double X[2];
};

#endif // EQUATION_SYSTEM_H_