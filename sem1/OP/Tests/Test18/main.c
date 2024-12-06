#include <stdio.h>

struct s {
    int x;
    int y;
};

int main() {
    struct s s1 = {1, 2};
    struct s s2;

    s2 = s1;
    
    if (s1.x == s2.y) {
        printf("1");
    }

    // if (s1 == s2) {
    //     printf("1");
    // }
}