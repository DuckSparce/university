#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ARRAY_SIZE 100000

int compare(int * a, int * b)
{
    return *b - *a;
}

void insertionSort(int * array, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main()
{
    LARGE_INTEGER timestart1,timend1,timestart2,timend2;
    LARGE_INTEGER limit1,limit2;
    
    // fill an array
    srand(time(NULL));

    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }

    QueryPerformanceCounter(&limit1);
    QueryPerformanceCounter(&timestart1);
    
    // quicksort
    qsort(arr1, ARRAY_SIZE, sizeof(int), compare);
    
    QueryPerformanceCounter(&timend1);
    printf("The quick sort time is %lf.\n", (double)(timend1.QuadPart - timestart1.QuadPart)*1000000/limit1.QuadPart);

    QueryPerformanceCounter(&limit2);
    QueryPerformanceCounter(&timestart2);

    // insertion sort
    insertionSort(arr2, ARRAY_SIZE);

    QueryPerformanceCounter(&timend2);
    printf("The insertion sort time is %lf.\n", (double)(timend2.QuadPart - timestart2.QuadPart)*1000000/limit2.QuadPart);

    //compare results
    int areEqual = 1;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr1[i] != arr2[i])
        {
            areEqual = 0;
            break;
        }
    }
    printf("The arrays are%sequal.", areEqual ? " " : " not ");

    return 0;
}