#include <stdio.h>
//#define USE_FIRST

#ifdef USE_FIRST
#define w(x, y, z) ((x&y)&(x|z))&(!x^y)
#else
#define w(x, y, z) (((x|y)&(z|y))&(z|x))
#endif

int main()
{
    int x, y, z;

    printf("Enter x, y, z (0 or 1): ");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    int w = w(x, y, z); 

    printf("w = %d\n", w);

    return 0;
}
