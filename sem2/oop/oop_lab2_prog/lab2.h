#ifndef LAB2_H
#define LAB2_H

// Функція вертає тривалість безперебійної роботи споживачів (год)
//  потужністю dW (Вт) від джерела аварійного живлення ємністю dC (Вт*год)
//  з коефіцієнтом перетворення dRatio (0 < dRatio < 1).
double GetTimeOfOperationInHours(double dW, double dC, double dRatio);

#endif // LAB2_H