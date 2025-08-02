#include <stdio.h>

void shift(int *x, int k)
{
    if (k > 0)
        *x = *x << k;
    else
        *x = *x >> -k;
    return;
}
void print_result(int x)
{
    printf("Hexadecimal after:%x\nDecimal:%d\n", x, x);
    return;
}
int main(void)
{
    int x, k;
    printf("number:");
    scanf("%d", &x);
    printf("left shift:");
    scanf("%d", &k);
    printf("Hexadecimal before:%x\n", x);
    shift(&x, k);
    print_result(x);
    return 0;
}