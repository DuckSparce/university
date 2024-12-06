#include <stdio.h>

#define SQUARE(X) X+X
#define PSQR(Х) printf( “sqrt “ #Х ” equals %d.\n" , ((Х)*(Х)))

#define N 100

int printfsmth()
{
    printf("%d", N);
}

#undef N
#define N 1000

int main()  
{
    // int z = SQUARE(2);
    
    // printf("%d", 2 * z);
    printfsmth(N);

    printf("%d", N);

    return 0;
}