#include <stdio.h>
#include "util.h"

float_bits float_twice(float_bits f)
{
    unsigned exp = f >> 23 & 0xFF;
    if (exp == 0xFF) // NaN or Infinity
    {
        return f;
    }
    if (exp == 0) // Denormalized
    {
        unsigned frac = f & 0x7FFFFF;
        frac = (frac << 1) & 0x7FFFFF;
        return (f & 0x80000000) | frac;
    }
    exp++;
    if (exp == 0xFF) // exp + 1 = Infinity
    {
        return (f & 0x80000000) | 0x7F800000;
    }
    return (f & 0x807FFFFF) | exp << 23;
}

int main()
{
    printf("%f", fb2f(float_twice(f2fb(-1e-10))));
    return 0;
}