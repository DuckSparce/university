#include <stdio.h>

int function(int, int);

int main()
{
    function(1, 5);
}

int function(int count, int elem)
{
    elem--;
    int num = 0;
    scanf("%d", &num);
    
    if (elem > 0) {
        function(count + 1, elem);
    }

    printf("%d - %d\n", count, num);
}