#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <A> <B> <n>\n";
        return 1;
    }

    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    double h = (b - a) / n;

    for (double x = a; x < b; x += h) {
        double y = (pow(cos(x), 2) + pow(cos(x), 3)) / fabs(1 / x);
    }
}