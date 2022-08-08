#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 2;

    const int *pa = &a;
    printf("a is %d\n", a);
    *pa = 2;
    printf("a is %d\n", a);

    int * const pb = &b;
    *pb = 3;

}