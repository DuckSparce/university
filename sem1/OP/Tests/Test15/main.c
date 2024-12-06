#include <stdio.h>

struct S {
    int n;
};

int main() {
    struct S s1 = {5};
    struct S s2 = {6};
    s2 = s1;
    printf("%d", s2.n);
}