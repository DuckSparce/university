#define _CRT_SECURE_NO_WARNINGS
#include "lab2.h" 
#include <bitset> 

// ������� ������� �����, ��� �������� �������� �������� ������ ������
// �������� ����� �� ������ ������� ���
unsigned int ShiftRight(int uiNumber, unsigned int uiBits) {
	return ((uiNumber >> uiBits) | (uiNumber << (32 - uiBits)));
}