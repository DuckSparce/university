#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXSIZE 100

int isSimple(int matrix[MAXSIZE][MAXSIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i != j && matrix[i][j] != matrix[j][i])
			{
				return 0;
			}
		}
	}

	return 1;
}

int matrixOutput(int matrix[MAXSIZE][MAXSIZE], int size, int optional)
{
	int edges = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
			if (matrix[i][j] == 1)
			{
				edges++;
			}
		}
		printf("\n");
	}

	if (optional) {
		if (isSimple(matrix, size))
		{
			edges /= 2;
		}

		printf("Number of vertices: %d. Number of edges: %d.\n", size, edges);
	}

	return 0;
}

int task1()
{
	int size = 0;
	printf("Enter matrix G, H, G1 and H1 size (up to %d): ", MAXSIZE);
	scanf("%d", &size);
	if (size > MAXSIZE || size < 1) {
		printf("Wrong value entered. It should be positive and less than %d. End of program.", MAXSIZE);
		return 1;
	}

	printf("Graph G:\n");
	int G[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &G[i][j]);
			if ((G[i][j] != 0) && (G[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
			if ((i == j) && G[i][j] == 1)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}
	
	printf("Graph H:\n");
	int H[MAXSIZE][MAXSIZE] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &H[i][j]);
			if ((H[i][j] != 0) && (H[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
			if ((i == j) && H[i][j] == 1)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}

	printf("Graph G1:\n");
	int G1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &G1[i][j]);
			if ((G1[i][j] != 0) && (G1[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
			if ((i == j) && G1[i][j] == 1)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}

	printf("Graph H1:\n");
	int H1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &H1[i][j]);
			if ((H1[i][j] != 0) && (H1[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
			if ((i == j) && H1[i][j] == 1)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}

	printf("Complement of G:\n");
	int GComplement[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j) {
				continue;
			}
			GComplement[i][j] = !G[i][j];
		}
	}
	matrixOutput(GComplement, size, 1);

	printf("Complement of G1:\n");
	int G1Complement[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j) {
				continue;
			}
			G1Complement[i][j] = !G1[i][j];
		}
	}
	matrixOutput(G1Complement, size, 1);

	printf("Conjunction of G and H:\n");
	int GandH[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GandH[i][j] = G[i][j] && H[i][j];
		}
	}
	matrixOutput(GandH, size, 1);

	printf("Conjunction of G1 and H1:\n");
	int G1andH1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			G1andH1[i][j] = G1[i][j] && H1[i][j];
		}
	}
	matrixOutput(G1andH1, size, 1);

	printf("Disjunction of G and H:\n");
	int GorH[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GorH[i][j] = G[i][j] || H[i][j];
		}
	}
	matrixOutput(GorH, size, 1);

	printf("Disjunction of G1 and H1:\n");
	int G1orH1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			G1orH1[i][j] = G1[i][j] || H1[i][j];
		}
	}
	matrixOutput(G1orH1, size, 1);

	printf("Difference of G and H:\n");
	int GwithoutH[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GwithoutH[i][j] = G[i][j] && !H[i][j];
		}
	}
	matrixOutput(GwithoutH, size, 1);

	printf("Difference of G1 and H1:\n");
	int G1withoutH1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			G1withoutH1[i][j] = G1[i][j] && !H1[i][j];
		}
	}
	matrixOutput(G1withoutH1, size, 1);

	printf("Symmetric difference of G and H:\n");
	int notGandH[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			notGandH[i][j] = G[i][j] ^ H[i][j];
		}
	}
	matrixOutput(notGandH, size, 1);

	printf("Symmetric difference of G1 and H1:\n");
	int notG1andH1[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			notG1andH1[i][j] = G1[i][j] ^ H1[i][j];
		}
	}
	matrixOutput(notG1andH1, size, 1);

	return 0;
}

void printStack(int stack[MAXSIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (stack[i] == -1)
		{
			break;
		}
		printf("%d ", stack[i] + 1);
	}
	printf("\n");
}

void printQueue(int queue[MAXSIZE], int size)
{
	int i = 0;
	
	while (queue[i] == -1)
	{
		i++;
	}

	for (i; i < size; i++)
	{
		if (queue[i] == -1)
		{
			break;
		}
		printf("%d ", queue[i] + 1);
	}
	printf("\n");
}

int task2()
{
	int size = 0;
	printf("Enter number of vertices (up to %d): ", MAXSIZE);
	scanf("%d", &size);
	if (size > MAXSIZE || size < 1) {
		printf("Wrong value entered. It should be positive and less than %d. End of program.", MAXSIZE);
		return 1;
	}

	//Input
	printf("Enter graph data (adjacency matrix):\n");
	int matrix[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &matrix[i][j]);
			if ((matrix[i][j] != 0) && (matrix[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
			if ((i == j) && matrix[i][j] == 1)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}

	//DFS
	int current = 0;
	printf("Enter starting point for DFS: ");
	scanf("%d", &current);

	int stack[MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		stack[i] = -1;
	}
	int visitedDFS[MAXSIZE] = { 0 };
	visitedDFS[--current] = 1;

	int top = 0;
	stack[top] = current;

	printf("DFS:\nv(i)\tstack\n%d\t%d\n", current + 1, current + 1);

	while (top != -1)
	{
		for (int i = 0; i < size; i++)
		{
			if (matrix[current][i] == 1 && !visitedDFS[i])
			{
				++top;
				stack[top] = i;
				visitedDFS[i] = 1;

				printf("%d\t", i + 1);
				printStack(stack, size);
				
				current = i;
				i = 0;
			}
		}

		stack[top--] = -1;
		printf("-\t");
		printStack(stack, size);
	}

	//BFS
	printf("Enter starting point for BFS: ");
	scanf("%d", &current);
	
	int queue[MAXSIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		queue[i] = -1;
	}

	int visitedBFS[MAXSIZE] = { 0 };
	visitedBFS[--current] = 1;
	
	top = 0;
	int rear = 0;
	queue[rear] = current;

	printf("BFS:\nv(i)\tqueue\n%d\t%d\n", current + 1, current + 1);

	while (rear != size)
	{
		current = queue[rear];
		for (int i = 0; i < size; i++)
		{
			if (matrix[current][i] == 1 && !visitedBFS[i])
			{
				++top;
				queue[top] = i;
				visitedBFS[i] = 1;

				printf("%d\t", queue[top] + 1);
				printQueue(queue, size);
			}
		}

		queue[rear++] = -1;
		printf("-\t");
		printQueue(queue, size);
	}

	return 0;
}

int task3()
{
	int size = 0;
	printf("Enter number of vetrices (up to %d): ", MAXSIZE);
	scanf("%d", &size);
	if (size > MAXSIZE || size < 1) {
		printf("Wrong value entered. It should be positive and less than %d. End of program.", MAXSIZE);
		return 1;
	}


	//Input
	printf("Enter weighted graph (adjacency matrix):\n");
	int matrix[MAXSIZE][MAXSIZE] = { 0 };	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &matrix[i][j]);
			
			if (matrix[i][j] < 0)
			{
				printf("Wrong number entered. Number should be 0 or higher. End of program.");
				return 1;
			}

			if ((i == j) && matrix[i][j] != 0)
			{
				printf("Wrong number entered. Elements of the main diagonal"
					"should be 0, because the graph is considered to be simple. End of program.");
				return 1;
			}
		}
	}

	int startVertex = 0;					// start vertex (should be end vertex)
	printf("Enter the starting point: ");
	scanf("%d", &startVertex);
	startVertex--;
	int curVertex = startVertex;			// current vertex
	int minVertex = 0;						// vertex with the cheapest price to it for current iteration

	char path[MAXSIZE * 10] = "1";
	int totalPrice = 0;						// eventual price of path
	int minPrice = 1000;					// price of an edge with the cheapest price for current iteration
	
	char temp[] = " - 0";

	for (int i = 0; i < size - 1; i++)
	{	
		for (int j = 0; j < size; j++)
		{
			if (curVertex != j &&
				j != startVertex &&
				matrix[curVertex][j] < minPrice &&
				matrix[curVertex][j] > 0)
			{
				minPrice = matrix[curVertex][j];
				minVertex = j;
			}
		}

		for (int k = 0; k < size; k++)
		{
			matrix[k][minVertex] = -1;
		}

		sprintf(path, "%s - %d", path, minVertex + 1);
		totalPrice += minPrice;

		minPrice = 1000;
		curVertex = minVertex;
	}
	totalPrice += matrix[curVertex][startVertex];
	sprintf(path, "%s - %d", path, startVertex + 1);

	printf("The path: %s.\n", path);
	printf("The price of path is %d.\n", totalPrice);

	return 0;
}

int task4()
{
	//Size input
	int size = 0;
	printf("Enter number of vertices (up to %d): ", MAXSIZE);
	scanf("%d", &size);
	if (size > MAXSIZE || size < 1) {
		printf("Wrong value entered. It should be positive and less than %d. End of program.", MAXSIZE);
		return 1;
	}

	//Matrix input
	printf("Enter graph data (adjacency matrix):\n");
	int matrix[MAXSIZE][MAXSIZE] = { 0 }; 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &matrix[i][j]);
			if ((matrix[i][j] != 0) && (matrix[i][j] != 1))
			{
				printf("Wrong number entered. It should be 0 or 1. End of program.");
				return 1;
			}
		}
	}

	int method = 0;
	printf("What method to use?\n(1 - Matrix multiplication, 2 - Warshall algorithm) : ");
	scanf("%d", &method);
	
	switch(method){
	case 1:
		printf("1 method: Matrix multiplication\n");

		int tempValue = 0;
		int poweredMatrix[MAXSIZE][MAXSIZE] = { 0 };
		int startMatrix[MAXSIZE][MAXSIZE] = { 0 };
		int tempMatrix[MAXSIZE][MAXSIZE] = { 0 };
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				startMatrix[i][j] = matrix[i][j];
				poweredMatrix[i][j] = matrix[i][j];
			}
		}

		for (int m = 2; m < size + 1; m++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					for (int k = 0; k < size; k++)
					{
						tempValue += poweredMatrix[i][k] && startMatrix[k][j];
					}
					tempMatrix[i][j] = !!tempValue;
					tempValue = 0;
				}
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					poweredMatrix[i][j] = tempMatrix[i][j];
				}
			}
			
			printf("M^%d\n", m);
			matrixOutput(poweredMatrix, size, 0);

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					matrix[i][j] = matrix[i][j] || poweredMatrix[i][j];
				}
			}
		}

		break;
	case 2:
		printf("2 method: Warshall algorithm\n");
		
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
				}
			}
		}
		
		break;
	default: 
		printf("Wrong number entered. End of program.\n");
		return 1;
	}
	
	printf("Reachability matrix:\n");
	matrixOutput(matrix, size, 0);
	return 0;
}

int main()
{
	//task1();
	//task2();
	//task3();
	task4();
}