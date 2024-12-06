#include <stdio.h>


class A {
	int a;
public:
	A(int y) :a(y) {}
	A() : a(0) {};
};

void main()
{
	A a = 4;
	A b = a;
	printf("%d");
}
