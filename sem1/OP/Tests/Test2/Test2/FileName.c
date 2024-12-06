#include <stdio.h>
#include <math.h>

int main()
{
	int bigIntValue = 2000000000;
	long long longResult = 1000000000LL + bigIntValue;
	printf("%lld\n", longResult);

	if (2000000000 + 1000000000 > 0)
		printf("yes\n");
	else
		printf("no\n");

	printf("%zu %zu", sizeof(int), sizeof(long long));
	//char letter = 5;
	//printf("%c", letter);t

	//float a = 3.4E37 * 10;
	//printf("%f\n", a); // good
	//a *= 10;
	//printf("%f\n", a); // inf	
	//
	//printf("%d\n", isinf(a));

	//printf("%lf\n", asin(2));

	//float a, b;
	//b = 2.0e20 + 1.0;
	//a = b - 2.0e20;
	//printf("%f\n", a); // unpredictable result

	//printf("%d", sizeof(int));


	return 0;
}
