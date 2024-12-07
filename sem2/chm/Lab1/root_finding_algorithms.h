#ifndef ROOT_FINDING_ALGORITHMS_H
#define ROOT_FINDING_ALGORITHMS_H

bool isIntervalCorrect(double a, double b, double eps);

double dichotomy(double, double, double);

double interpolation(double, double, double);

double tangent(double a, double b, double eps);

double iteration(double a, double b, double eps);

#endif