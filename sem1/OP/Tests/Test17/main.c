#include <stdio.h>

struct s
{
    int field;
};

int main()
{
    int a = 5;
    struct s s1 = {a};
    struct s s2 = s1;
    s1.field = 9;
    printf("%d", s2.field);
}