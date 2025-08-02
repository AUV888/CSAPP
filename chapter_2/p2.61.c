#include <stdio.h>
/*
!(a ^ b) is equivalent to a == b
*/

int any_bit_eq_1(int x) // 0xFFFFFFFF;
{
    return !~x;
}

int any_bit_eq_0(int x) // 0x00000000;
{
    return !x;
}

int least_sig_byte_eq_FF(int x) // 0x123456FF
{
    x = x & 0xFF;
    return !(x ^ 0xFF);
}

int most_sig_byte_eq_FF(int x) // 0xFF234567
{
    x = x & 0xFF000000;
    return !(x ^ 0xFF000000);
}

int main()
{
    printf("%d", most_sig_byte_eq_FF(0xFF57966E));
    return 0;
}