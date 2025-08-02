#include <stdio.h>
/*
*Use xor(^) to count the num of '1'
*e.g. for 0b1001, 1^0^0^1=0; for 0b1101, 1^1^0^1=1
*/

int odd_ones(unsigned x)
{
    x = x ^ (x >> 16);//the new x = (x_left16)^(x_right16)
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}

int main()
{
    printf("%d", odd_ones(0b11011111u));
    return 0;
}