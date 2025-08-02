#include <stdio.h>
#include "util.h"

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0xFF && frac) // NaN
    {
        return f;
    }
    if (exp == 0) // Denormalized
    {
        frac >>= 1;
        return (sign << 31) | frac;
    }
    if (exp == 1) // f/2 is denormalized
    {
        frac = (frac >> 1) + 0x400000;
        return (sign << 31) | frac;
    }
    exp--;
    return (sign << 31) | (exp << 23) | frac;
}

int main()
{
    printf("%f",fb2f(float_half(f2fb(0/0.0))));
    return 0;
}