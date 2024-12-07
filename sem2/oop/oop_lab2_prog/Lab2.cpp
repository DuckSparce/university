#include <cstdio>
#include <cfloat>
#include <cmath>
#include "lab2.h"

//  Функція вертає тривалість безперебійної роботи споживачів (год)
//  потужністю dW (Вт) від джерела аварійного живлення ємністю dC (Вт*год)
//  з коефіцієнтом перетворення dRatio (0 < dRatio < 1)
double GetTimeOfOperationInHours(double dW, double dC, double dRatio) {
	if (dW <= 0 || dW > 1000000 || isinf(dW) || isnan(dW) ||
		dC <= 0 || dC > 1000000 || isinf(dC) || isnan(dC) ||
		dRatio <= 0 || dRatio >= 1 || isinf(dRatio) || isnan(dRatio)) {
		return NAN;
	}
	return (dC * dRatio / dW);
}