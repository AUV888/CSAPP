#include <stdio.h>
#include "util.h"

float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0xFF && frac) // NaN
        return f;
    else
        return (exp << 23) | frac;
}

int main()
{
    printf("%f",fb2f(float_absval(f2fb(-1.5))));
    return 0;
}