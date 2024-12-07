#include "functions.h"
#include <stdio.h>

int isInPruferCode(int vertice, int * pruferCode, int size)
{
    for (int i = 0; i < size - 2; i++)
    {
        if (vertice == pruferCode[i])
        {
            return 1;
        }
    }

    return 0;
}

void buildTree(int * pruferCode, int * vertices, int size)
{
    // build all edges except the last one
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!isInPruferCode(j + 1, pruferCode, size) && vertices[j] == 0)
            {
                printf("%d edge: %d-%d\n", i + 1, pruferCode[i], j + 1);
                vertices[j] = 1;
                pruferCode[i] = -1;
                break;
            }
        }
    }
    
    // find last edge from vertices that left in vertices array
    for (int i = 0; i < size; i++)
    {
        if (vertices[i] == 0)
        {
            for (int j = 0; j < size; j++)
            {
                if (vertices[j] == 0 && j != i)
                {
                    printf("last edge: %d-%d", i + 1, j + 1);
                    break;
                }
            }
            break;
        }
    }
}