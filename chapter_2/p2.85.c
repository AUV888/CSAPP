#include <stdio.h>
#include <string.h>

float get_float(unsigned *num)
{
    float result;
    memcpy(&result, num, 4);
    return result;
}

int main()
{
    unsigned num_7 = 0x40DFFFFF;
    unsigned largest_odd = 0x4B7FFFFF;               // 2^24 - 1
    unsigned reciprocal_small_pos_norm = 0x7E800000; // 2^126, which is 1 / 2^(-126)
    printf("number 7.0 is: %f\n", get_float(&num_7));
    printf("largest odd is: %f\n", get_float(&largest_odd));
    printf("reciprocal of the smallest positive normalied value is: %f\n", get_float(&reciprocal_small_pos_norm));
    return 0;
}