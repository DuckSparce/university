#include <stdio.h>

int sumSequence(int);

int main()
{
    int num = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Result: %d", sumSequence(num));

    return 0;
}

int sumSequence(int count)
{
    if (count > 0)
    {
        return count + sumSequence(count - 1);
    }
    else
    {
        return 0;
    }
}