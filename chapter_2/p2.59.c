#include <stdio.h>
int return_least_sig_byte(int x, int y)
{
    x = x & 0xFF;
    y = (y >> 8) << 8;
    return x | y;
}
int main(void)
{
    int x = 0x89ABCDEF, y = 0x76543210;
    printf("result=%x\n", return_least_sig_byte(x, y));
    return 0;
}