#define MSG "Please, enter data"

#include <stdio.h>
#include <string.h>

int main()
{

	//printf("%s, %#x, %c\n", "Testing", "string", *"literals");
	////Output: Testing, 0x77519c34, l
	//printf(MSG);

	const char szTest1[] = "Test string";
	
	//FILE* fp = fopen("file.txt", "w+");

	printf("%d", strcmp("test", "test1"));
	return 0;
}