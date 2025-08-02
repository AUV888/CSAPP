#include <stdio.h>
/*
*如果x是正数，右数第n位及其左侧全为0
*如果x是负数，右数第n位及其左侧全为1
*尝试将y与x的反码比较
*/
int fits_bits(int x, int n)
{
    x >>= (n - 1);
    return !x || !(~x);
}

int main()
{
    printf("%d", fits_bits(-32769, 16));
    return 0;
}