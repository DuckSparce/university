#include <stdio.h> 

int main()
{
	int arr[100];
	int(*parr)[100] = &arr;

	printf("%p %p", arr, parr);

	/*
	printf("Print into terminal before redirection");
	freopen("example.out", "w", stdout);
	printf("Print into file after redirection");*/

	return 0;
}