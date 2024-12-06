#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // FILE* f1 = fopen("f1.txt", "r");
    
    // char str[10000];
    // fgets(str, 10000, f1);
    
    // char * words[100];
    // char * word = strtok(str, ", ");
    // int i = 0;
    // while (word)
    // {
    //     words[i++] = word;
    //     word = strtok(NULL, ", ");
    // }
    // fclose(f1);

    // FILE* f2 = fopen("f2.txt", "w");
    // fputs("Array = { ", f2);
    // i = 0;
    // while (words[i])
    // {
    //     fputs(words[i++], f2);
    
    //     fputs(" ", f2);
    // }
    // fputs("}\nNumber of words: ", f2);
    // sprintf(str, "%d", i);
    // fputs(str, f2);
    
    char* str1 = "word";
    char* str2 = "word";
    if (str1 == str2)
    {
        printf("Hi");
    }
    else 
    {
        printf("hello");
    }

    return 0;
}