#define _CRT_SECURE_NO_WARNINGS
#include "lab2.h" 
#include <bitset> 

// функція повертає число, яке утворене циклічним побітовим зсувом вправо
// заданого числа на задану кількість бітів
unsigned int ShiftRight(int uiNumber, unsigned int uiBits) {
	return ((uiNumber >> uiBits) | (uiNumber << (32 - uiBits)));
}