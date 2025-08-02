#include "util.h"
#include <string.h>

float fb2f(float_bits x)
{
    float result;
    memcpy(&result, &x, 4);
    return result;
}
float_bits f2fb(float x)
{
    float_bits result;
    memcpy(&result, &x, 4);
    return result;
}