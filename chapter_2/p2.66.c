#include <stdio.h>

int leftmost_one(unsigned x) // 0b00101100
{
    x |= (x >> 1); // 0b00101100 | 0b00010110 = 0b00111100
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16); // 0b00111111
    return x ^ (x >> 1);
}

int main()
{
    printf("%d", leftmost_one(0xFF00));
    return 0;
}