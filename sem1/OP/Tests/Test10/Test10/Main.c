#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//int main(void)
//{
//	char mesg[] = "Test-string|in.demonstrational purpose!";
//	char* ptr;
//
//	puts(mesg);
//	ptr = strtok(mesg, " |.-");
//	puts(mesg);
//	while (ptr != NULL)
//	{
//		puts(ptr);
//		ptr = strtok(NULL, " |.-");
//	}
//	puts(mesg);
//
//	return 0;
//}

int test1()
{
	char str[30] = "20.30300 This is test";
	char* ptr;
	double ret;

	ret = strtod(str, &ptr);
	printf("The number(double) is %lf\n", ret);
	printf("String part is |%s|", ptr);

	getchar();
	return(0);
}

int test2()
{
	char str[100] = "";
	fgets(str, sizeof(str), stdin);
	const int size = strlen(str);

	str[0] = toupper(str[0]);
	for (int i = 1; i < size; i++)
	{
		if (str[i - 1] == ' ')
		{
			str[i] = toupper(str[i]);
		}
		else
		{
			str[i] = tolower(str[i]);
		}
	}

	char* word = strtok(str, " ");
	word[0] = toupper(word[0]); 
	while (word != NULL)
	{
		int size = strlen(word);

		printf("%s ", word);
		word = strtok(NULL, " ");
	}
	
	puts(str);


	return 0;
}

int test3()
{
	char arr[50] = { 0 };
	char sym = getchar();
	int i = 0;
	while (sym != '\n')
	{
		arr[i++] = sym;
		sym = getchar();
	}

	printf(arr);
	return 0;
}
int main()
{
	test3();
}