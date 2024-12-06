#include <stdio.h>

void swap(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int* max(int * arr, int n)
{
    int * maxPtr = arr;
    for(int i = 1; i < n; i++)
    {
        if(*maxPtr < *(arr + i))
        {
            maxPtr = arr + i;
        }
    }
    return maxPtr;
}

int* min(int * arr, int n)
{
    int * minPtr = arr;
    for(int i = 1; i < n; i++)
    {
        if(*minPtr > *(arr + i))
        {
            minPtr = arr + i;
        }
    }
    return minPtr;
}

int main()
{
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };

    swap(max(arr, 10), min(arr, 10));

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}