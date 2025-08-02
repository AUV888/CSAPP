#include <stdio.h>

int main(void)
{
    unsigned int s1 = 0x100u, s2 = 0x101u;
    printf("s1 - s2 > 0 result: %d\ns1 > s2 result: %d\n", s1 - s2 > 0, s1 > s2);
    return 0;
}