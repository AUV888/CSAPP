#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    int mov = i << 3;
    x = x & ~(0xFF << mov);
    x = x | ((int)b << mov);
    return x;
}

int main(void)
{
    printf("result=%x\n", replace_byte(0x12345678, 0, 0xAB));
    return 0;
}