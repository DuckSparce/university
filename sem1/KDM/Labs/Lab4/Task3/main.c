#include <stdio.h>

const int table[16][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 1 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 1 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 1 },
        { 0, 1, 1, 0 },
        { 0, 1, 1, 1 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 1 },
        { 1, 0, 1, 0 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 },
        { 1, 1, 1, 1 },
    };

void printElementaryConjunction(const int combination[4])
{
    printf("(%s", combination[0] ? "" : "!");
    printf("W^");
    printf("%s", combination[1] ? "" : "!");
    printf("X^");
    printf("%s", combination[2] ? "" : "!");
    printf("Y^");
    printf("%s", combination[3] ? "" : "!");
    printf("Z)");
}

void printElementaryDisjunction(const int combination[4])
{
    printf("(%s", combination[0] ? "!" : "");
    printf("Wv");
    printf("%s", combination[1] ? "!" : "");
    printf("Xv");
    printf("%s", combination[2] ? "!" : "");
    printf("Yv");
    printf("%s", combination[3] ? "!" : "");
    printf("Z)");
}

void printFDNF(const int numbers[16])
{
    int last = 0;
    for (int i = 0; i < 16; i++)
    {
        if (numbers[i])
        {
            last = i;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        if (numbers[i])
        {
            printElementaryConjunction(table[i]);
            if (i == last)
            {
                break;
            }
            printf("v");
        }
    }

    printf("\n");
}

void printFCNF(const int numbers[16])
{
    int last = 0;
    for (int i = 0; i < 16; i++)
    {
        if (!numbers[i])
        {
            last = i;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        if (!numbers[i])
        {
            printElementaryDisjunction(table[i]);
            if (i == last)
            {
                break;
            }
            printf("^");
        }
    }

    printf("\n");
}

int main()
{
    int numbers[16] = { 0 };

    printf("Enter your numbers (-1 means end of input): ");
    
    int temp = 0;
    scanf("%d", &temp);
    while (temp != -1)
    {
        numbers[temp] = 1;
        scanf("%d", &temp);
    }

    printf("Final disjunctive normal form:\n");
    printFDNF(numbers);
    
    printf("Final conjunctive normal form:\n");
    printFCNF(numbers);

    return 0;
}
