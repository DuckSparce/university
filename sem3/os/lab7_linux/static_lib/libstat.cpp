#include "libstat.h"

#include <iostream>
#include <cmath>

void libstat_func() {
    std::cout << "Inside static library tabulation function: a = 1, b = 100, n = 100.\n";

    double a = 1;
    double b = 100;
    int n = 100;
    double h = (b - a) / n;

    for (double x = a; x < b; x += h) {
        double y = (pow(cos(x), 2) + pow(cos(x), 3)) / fabs(1 / x);
        std::cout << "For x = " << x << " y = " << y << '\n';
    }

    std::cout << "End of static library function.\n";
}
