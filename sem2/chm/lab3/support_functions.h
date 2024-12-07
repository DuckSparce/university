#ifndef SUPPORT_FUNCTIONS_H_
#define SUPPORT_FUNCTIONS_H_

double determinant(double[2][2]);

double determinant(double[3][3]);

double isInvertible(double matrix[3][4]);

bool inverse(double[3][3], double[3][3]);

bool multiplication(double[3][3], double[3][3], double[3]);

bool swap(double[3][4], unsigned int, unsigned int);

#endif // SUPPORT_FUNCTIONS_H_
