#include <stdio.h>
#include <string.h>

#define MAXCHARS 1000
int main()
{
    char str[MAXCHARS];

    printf("Enter your string:\n");
    fgets(str, MAXCHARS, stdin);

    char * numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    char *delimeters = " ,\n";
    char *word = strtok(str, delimeters);
    while (word != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            if (!strcmp(word, numbers[i]))
            {
                printf("%d ", i);
            }
        }

        word = strtok(NULL, delimeters);
    }
}