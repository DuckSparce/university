#include <stdio.h>

int main() {
    // char str1[] = "Test";
    // //equals
    // char str2[] = {'T', 'e', 's', 't', '\0'};
    // printf("%u", sizeof(str2));
    // printf("%d", strlen(str2));

    // char str3[10];
    // scanf("%s", str3);
    // printf("%s", str3);

    int width = 0, number = 543, precision = 0;
    double weight = 342.423523;
    printf ("Bвeдіть ширину поля:\n");
    scanf("%d", &width) ;
    printf ("Введене значення: %*d:\n", width, number) ;
    printf("Teпер введіть ширину та точність:\n") ;
    scanf("%d %d", &width, &precision);
    printf("Вага = %*.*f\n", width, precision, weight);
}