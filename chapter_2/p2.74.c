#include <stdio.h>

int tsub_ok(int x, int y)
{
    // n-p=p or p-n=n
    int sign_x = (x >> 31) + 1;
    int sign_y = (y >> 31) + 1;
    int sign_result = ((x - y) >> 31) + 1;
    int result = (sign_x ^ sign_y) & (sign_x ^ sign_result);
    return !result;
}

int main()
{
    int x = -2147483648, y = 11;
    printf("%d", tsub_ok(x, y));
    return 0;
}