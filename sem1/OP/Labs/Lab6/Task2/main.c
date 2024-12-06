#include <stdarg.h>
#include <stdio.h>

int main()
{
    printf("Given words: apple, pear, cherry, pineapple, banana.\n");

    checkDoubling("apple", "pear", "cherry", "pineapple", "banana", NULL);
}

void checkDoubling(char* word, ...)
{
    printf("Words with doubling:");
    char** currentWord = &word;
    while (*currentWord)
    {
        int size = strlen(*currentWord);
        for (int i = 0; i < size - 1; i++)
        {
            if ((*currentWord)[i] == (*currentWord)[i + 1])
            {
                printf(" %s,", *currentWord);
                break;
            }
        }
        currentWord++;
    }
    printf("\b.\n");
}