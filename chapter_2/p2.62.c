#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
    int x = ~0x0;
    return !((x >> 1) ^ ~0x0);
}

int main()
{
    printf("right shift arithmetic:%d\n", int_shifts_are_arithmetic());
    return 0;
}