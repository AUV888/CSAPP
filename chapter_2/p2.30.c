#include <stdio.h>
#include <limits.h>
int tadd_ok(int x, int y)
{
	return !(x + y > INT_MAX || x + y < INT_MIN);
}
int main(void)
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("Will the sum overflow?\n%d\n", tadd_ok(x, y));
	return 0;
}
