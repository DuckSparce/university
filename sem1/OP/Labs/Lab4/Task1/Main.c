#include <stdio.h>
#include <string.h>

#define MAXCHARS 1000

int main()
{
    // 1. Input data
    char str[MAXCHARS];
    printf("Enter your string:\n");
    fgets(str, MAXCHARS, stdin);

    char letter = 0;
    printf("Enter the character, you want to check the words for:\n");
    scanf("%c", &letter);

    char *delimeters = " .";
    int counter = 0;
    int max = 0;
    char maxWord[MAXCHARS];

    // 2. Divide sentence to words and find the max one
    char *word = strtok(str, delimeters);
    while (word != NULL)
    {
        int length = strlen(word);

        for (int i = 0; i < length; i++)
        {
            if (word[i] == letter)
            {
                counter++;
            }
        }

        if (counter > max)
        {
            max = counter;
            strcpy(maxWord, word);
        }

        counter = 0;
        word = strtok(NULL, delimeters);
    }

    // 3. Result output
    printf("Found word: %s\n", maxWord);

    return 0;
}