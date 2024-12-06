#include <stdio.h>
#include <string.h>

int main()
{
    FILE* in = fopen("in.txt", "r");
    FILE* out = fopen("out.txt", "w");

    if (in == NULL)
    {

        return 1;
    }

    int symbNum = 0;
    int replace = 0;
    char str[1000];
    fgets(str, 1000, in);
    
    char* word = strtok(str, " ");
    while (word != NULL)
    {
        if (strcmp(word, "test"))
        {
            fputs(word, out);
            fputs(" ", out);
            symbNum += strlen(word) + 1;
        }
        else
        {
            fputs("example ", out);
            symbNum += 8;
            replace++;
        }
        word = strtok(NULL, " ");
    }

    sprintf(str, "\nNumber of symbols: %d. Number of replacements: 0x = %o, hx = %x.", symbNum, replace, replace);
    fputs(str, out);

    fclose(in);
    fclose(out);

    return 0;
}