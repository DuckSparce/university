#include <stdio.h>
#include <stdlib.h>

#define RANGE { 1, 2, 3, 4, 5 }

typedef struct Element
{
    int argument;
    int image;
} elem_t;

int isFunction(const elem_t* list, const unsigned int size)
{
    const int range[] = RANGE;
    int rangeSize = sizeof(range) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        int argumentIndicator = 0;
        int imageIndicator = 0;

        // Check if is in range
        for (int j = 0; j < rangeSize; j++)
        {
            if (list[i].argument == range[j])
            {
                argumentIndicator = 1;
            }

            if (list[i].image == range[j])
            {
                imageIndicator = 1;
            }
        }

        if (!argumentIndicator || !imageIndicator)
        {
            return 0;
        }

        // Check for repetitions of the argument
        for (int j = i + 1; j < size; j++)
        {
            if (list[i].argument == list[j].argument)
            {
                return 0;
            }
        }
    }

    return 1;
}

int isInjection(const elem_t* list, const unsigned int size)
{
    // Check for repetitions of the image
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (list[i].image == list[j].image)
            {
                return 0;
            }
        }
    }

    return 1;
}

int isSurjection(const elem_t* list, const unsigned int size)
{
    int range[] = RANGE;
    int rangeSize = sizeof(range) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < rangeSize; j++)
        {
            if (list[i].image == range[j])
            {
                range[j] = 0;
                break;
            }
        }
    }

    for (int j = 0; j < rangeSize; j++)
    {
        if (range[j])
        {
            return 0;
        }
    }

    return 1;
}

int isBijection(const elem_t* list, const unsigned int size)
{
    return isInjection(list, size) && isSurjection(list, size);
}

int main()
{
    unsigned int size = 0;
    printf("Enter number of elements of the function: ");
    scanf("%u", &size);

    elem_t* list = calloc(size, sizeof(elem_t));

    printf("Enter list of elements of the function:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d", &list[i].argument, &list[i].image);
    }

    printf("The function is:%s injection,%s surjection,%s bijection.", 
                                    isInjection(list, size) ? "" : " not",
                                    isSurjection(list, size) ? "" : " not",
                                    isBijection(list, size) ? "" : " not");

    free(list);
    list = NULL;
}