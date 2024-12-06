#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
	/*
	unsigned int a;
	int b;
	double c;
	char d;
	scanf("%u %d %lf %c", &a, &b, &c, &d);

	printf("%u %d %lf %c", a, b, c, d);
	*/

	char ch;
	while ((ch = getchar()) != '#')
		putchar(ch);
	return 0;

}