#include <stdio.h>
#include <string.h>

#define MAXCHARS 1000

void decrypt(char*, char*, int, int);

int main()
{
    char src[MAXCHARS];
    printf("Enter your string (only lowercase literals):\n");
    fgets(src, MAXCHARS, stdin);

    unsigned int offset = 0;
    printf("Enter offset (between 1 and 25): ");
    scanf("%d", &offset);

    if (offset < 1 || offset > 25)
    {
        printf("Wrong offset entered. End of program.");
        return 1;
    }

    int size = strlen(src);
    char dst[MAXCHARS];

    decrypt(src, dst, size, offset);

    fputs(dst, stdout);
    return 0;
}

void decrypt(char* src, char* dst, int size, int offset)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (src[i] != ' ')
        {
            dst[i] = 'a' + (src[i] - 'a' + offset) % 26;
        }
        else
        {
            dst[i] = src[i];
        }
    }
}