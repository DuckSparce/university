#include <iostream>
#include <vector>

int main() {
    // Define the data points
    const std::vector<double> x_points = { 0, 1, 2 };
    const std::vector<double> y_points = { -1, 0, 3 };
    const size_t n = x_points.size();

    if (n != y_points.size()) {
	    std::cerr << "X and Y arrays must be the same size.";
        return 1;
    }

    // Initialize coefficients with zeros
    std::vector<double> coefficients(n, 0.0);

    for (size_t i = 0; i < n; i++) {
	    std::vector<double> new_coefficients(n, 0.0);

        if (i > 0) {
            // Handle first two coefficients for m > 0
            new_coefficients[0] = -x_points[0] / (x_points[i] - x_points[0]);
            new_coefficients[1] = 1.0 / (x_points[i] - x_points[0]);
        } else {
            // Handle first two coefficients for m = 0 (special case)
            new_coefficients[0] = -x_points[1] / (x_points[i] - x_points[1]);
            new_coefficients[1] = 1.0 / (x_points[i] - x_points[1]);
        }

        int startIndex = (i == 0) ? 2 : 1;

        for (size_t j = startIndex; j < n; j++) {
            if (i == j) continue;

            // Update coefficients from n-th point onwards (backwards)
            for (size_t k = n - 1; k >= 1; k--) {
                new_coefficients[k] = new_coefficients[k] * (-x_points[j] / (x_points[i] - x_points[j])) +
                    new_coefficients[k - 1] / (x_points[i] - x_points[j]);
            }

            // Update the first coefficient
            new_coefficients[0] *= -x_points[j] / (x_points[i] - x_points[j]);
        }

        // Update final coefficients based on yPoints
        for (size_t k = 0; k < n; k++) {
            coefficients[k] += y_points[i] * new_coefficients[k];
        }
    }

    //Output
    std::cout << (coefficients[0] < 0 ? "- " : "") << fabs(coefficients[0]);

	for (size_t i = 1; i < n; i++) {
        std::cout << (coefficients[i] < 0 ? " - " : " + ") << fabs(coefficients[i]) << "*x^" << i;
    }

    return 0;
}
