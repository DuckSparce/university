#include <stdio.h>
#include <math.h>

int main()
{
	//task1();
	//task2();
	//task3();
	//task4();
	//task6();

	return 0;
}


// Logical operations:
// !  - NOT     - negation
// &  - AND     - conjunction
// |  - OR      - disjunction
// ^  - XOR     - alternative OR ( mod 2 )
// == - EQUALS  - equivalence

// -> - IF THEN - implication
// (a -> b) should be changed to (!a | b)
// because C doesn't have specific operator for it

int task1()
{
	// function for solving a complex statement

	// all cases (2^3 = 8)
	int p[8] = { 0,0,0,0,1,1,1,1 };
	int q[8] = { 0,0,1,1,0,0,1,1 };
	int r[8] = { 0,1,0,1,0,1,0,1 };

	// (!(p -> q) == (!q -> r)) -> (p | !r) =
	// (!(!p | q) == (!!q | r)) -> (p | !r) =
	// !((p & !q) == (q | r)) | (p | !r))

	printf("p\tq\tr\t!q\t!r\tp & !q\t\tq | r\t\t!((p & !q) == (q || r))\tp | !r\t\tfinal\n");
	
	//printing every one of all 8 possible combinations
	for (int i = 0; i < 8; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",
			p[i], q[i], r[i], !q[i], !r[i], p[i] ^ !q[i], q[i] | r[i],
			!((p[i] & !q[i]) == (q[i] | r[i])), p[i] | !r[i],
			!((p[i] & !q[i]) == (q[i] | r[i])) || (p[i] | !r[i]));
	}

	return 0;
}

int task2()
{
	// function with the same code as task1()
	// just for checking the written answer for task 2

	// all cases (2^3 = 8)
	int p[8] = { 0,0,0,0,1,1,1,1 };
	int q[8] = { 0,0,1,1,0,0,1,1 };
	int r[8] = { 0,1,0,1,0,1,0,1 };

	// (p & r -> q) -> (p & q -> r) & (q & r -> p) =
	// !(!(p & r) | q) | ((!(p & q) | r) & (!(q & r) | p)) =
	//  |     A      |   |     B      |   |     C      |

	int isTautology = 1;

	printf("p\tq\tr\tp & r\t\tp & q\t\tq & r\t\tA\tB\tC\tfinal\n");

	//printing every one of all 8 possible combinations
	for (int i = 0; i < 8; i++)
	{
		if ((!(p[i] & r[i]) | q[i]) | ((!(p[i] & q[i]) | r[i]) & (!(q[i] & r[i]) | p[i])))
		{
			isTautology = 0;
		}
		printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n",
			p[i], q[i], r[i], p[i] & r[i], p[i] & q[i], q[i] & r[i],
			!(p[i] & r[i]) | q[i], !(p[i] & q[i]) | r[i], !(q[i] & r[i]) | p[i],
			!(!(p[i] & r[i]) | q[i]) | ((!(p[i] & q[i]) | r[i]) & (!(q[i] & r[i]) | p[i])));
	}

	if (isTautology)
	{
		printf("The statement is tautology.");
	}
	else
	{
		printf("The statement is not tautology.");
	}

	return 0;
}

// x  a  a  b  b
// y  a  b  a  b
// P  0  1  0  1
// Q  1  0  0  1

int task3()
{
	// a = 0
	// b = 1
	// Example: Q with x = a and y = b 
	//       is Q[0][1] = 0 (F)

	int P[2][2] = { {0, 1}, {0, 1} };
	int Q[2][2] = { {1, 0}, {0, 1} };
	
	// Formula 1
	// ∀y P(y, y) - ?

	int result1 = 1;

	for (int i = 0; i < 2; i++) 
	{
		// (1) if at least for 1 y the statement is wrong,
		// no need for further investigation
		if (!result1)
		{
			break;
		}
		
		// analyzing every single combination
		for (int j = 0; j < 2; j++)
		{
			// (1)
			if (i == j && P[i][j])
			{
				result1 = 0;
				break;
			}
		}
	}

	//printing out the result
	if (result1)
	{
		printf("For all y P(y, y) is true.\n");
	}
	else
	{
		printf("Not for all y P(y, y) is true.\n");
	}
	
	// Formula 2 
	// ∀x∃y !P(x, y) -> Q(x, y) - ?
	//      = !!P(x, y) | Q(x, y)
	//      = P(x, y) | Q(x, y)

	int result2 = 1;
	
	for (int i = 0; i < 2; i++)
	{
		int temp = 0;
		for (int j = 0; j < 2; j++)
		{
			// if we found one y that already matches the condition,
			// no need for further investigation
			if (P[i][j] | Q[i][j])
			{
				temp = 1;
				break;
			}
		}
		// if for this x there is no y that matches the condition,
		// the statement is false
		// no need for further investigation
		if (!temp)
		{
			result2 = 0;
			break;
		}
	}

	//printing out the result
	if (result2)
	{
		printf("For all x there exists y that !P(x, y) -> Q(x, y) is true.\n");
	}
	else
	{
		printf("Not for all x there exists y that !P(x, y) -> Q(x, y) is true.\n");
	}

	return 0;
}

int task4()
{
	// Given
	int U[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// Characteristic vectors
	int a[10] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
	int b[10] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };
	int c[10] = { 1, 1, 1, 0, 0, 0, 0, 1, 1, 1 };

	// (!B & C) & !A
	int vector1[10] = { 0 };
	int p1 = 0; // cardinality
	for (int i = 0; i < 10; i++) 
	{
		vector1[i] = (!b[i] & c[i]) & !a[i];
		if (vector1[i]) p1++;
	}

	// Output
	printf("Set1 = ");
	printSet(vector1, U);
	printf("\nCardinality of Set1 is %d.\n", p1);

	// !((A & !C) | B)
	int vector2[10] = { 0 };
	int p2 = 0; // cardinality
	for (int i = 0; i < 10; i++)
	{
		vector2[i] = !((a[i] & !c[i]) | b[i]);
		if (vector2[i]) p2++;
	}

	// Output
	printf("Set2 = ");
	printSet(vector2, U);
	printf("\nCardinality of Set2 is %d.\n", p2);

	// (A & !(!C & B)) & C
	int vector3[10] = { 0 };
	int p3 = 0; // cardinality
	for (int i = 0; i < 10; i++)
	{
		vector3[i] = (a[i] & !(!c[i] & b[i])) & c[i];
		if (vector3[i]) p3++;
	}

	// Output
	printf("Set3 = ");
	printSet(vector3, U);
	printf("\nCardinality of Set3 is %d.\n", p3);
	

	// Output of PowerSet3
	int set3[] = { 1, 2, 3 };
	printf("Here is power set of Set 3: ");
	generatePowerSet(set3, 3);

	return 0;
}

int printSet(int vector[], int U[])
{
	printf("{ ");
	for (int i = 0; i < 10; i++)
	{
		if (vector[i])
		{
			printf(" %d,", U[i]);
		}
	}
	printf("\b }");

	return 0;
}

// Function to generate the power set of a given set
int generatePowerSet(int set[], int n) {
	int totalSubsets = pow(2, n); // Total number of subsets is 2^n

	printf("{");
	// Iterate through all possible subsets
	for (int mask = 0; mask < totalSubsets; mask++) {
		printSubset(set, n, mask);
	}
	printf("\b }");

	return 0;
}

int printSubset(int set[], int n, int mask) {
	printf(" {");
	if (mask == 0)
	{
		printf(" },");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) {
			printf(" %d,", set[i]);
		}
	}
	printf("\b },");

	return 0;
}

int task6()
{
	int a = 59; // |B | C | D|
	int b = 32; // |B|
	int c = 35; // |C|
	int d = 30; // |D|
	int e = 8;  // |B & C|
	int f;      // |B & D|
	int g = 15; // |C & D|
	int h = 7;  // |B & C & D|

	// |B | C | D| = |B| + |C| + |D| - |B & C| - |B & D| - |C & D| + |B & C & D|
	// a = b + c + d - e - f - g + h
	f = -a + b + c + d - e - g + h;
	if (f < 0)
	{
		printf("This realization of ECD is not possible.\n");
		return 1;
	}
	else
	{
		printf("This realization of ECD is possible.\n");
	}

	printf("f = %d\n", f);
	
	// b' = a - c - d + g   - using diagram
	printf("b' = %d\n", a - c - d + g);
	printf("c' = %d\n", a - b - d + f);
	printf("d' = %d\n", a - c - b + e);
}