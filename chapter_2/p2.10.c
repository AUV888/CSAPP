#include <stdio.h>
void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
    return;
}
void reverse(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
    return;
}
int main()
{
    int a[] = {0x01, 0x02, 0x03, 0xa4, 0xa5};
    int cnt = sizeof(a) / sizeof(a[0]);
    reverse(a, cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}