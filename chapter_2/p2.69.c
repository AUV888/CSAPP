#include <stdio.h>
/*
* Shift n bits (n>=w) is Undefined Behavior
*/
unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    return x << n | (x >> (w - n - 1)) >> 1;
}

int main()
{
    printf("%x", rotate_left(0x12345678u, 31));
    return 0;
}