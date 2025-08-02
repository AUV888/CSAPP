#include <stdio.h>
/*
*this program is buggy when k=0 or k=w
*/
unsigned srl(unsigned x, int k) // 0b10110010u
{
    unsigned xsra = (int)x >> k; // 0b11101100u
    int w = sizeof(int) * 8;     // required: 0b00111111u
    int mov = w - k;
    unsigned mask = ~0 << mov;
    return xsra & ~mask;
}

int sra(int x, int k) // 0b10110010, 0b01001110
{
    int xsrl = (unsigned)x >> k; // 0b00101100,0b00010011
    int w = sizeof(int) * 8;
    int sign = !((~0 << (w - 1)) & x) - 1; // sign=0 when pos, 0xFFFF when neg
    return x | (~0 << (w - k)) & sign;
}

int main()
{
    printf("%u", sra(0x80000000u, 2));
    return 0;
}