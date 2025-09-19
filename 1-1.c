#include <stdio.h>
int max(int a, int b, int c)
{
	int d = (a > b) ? a : b;
	int e = (d > c) ? d : c;
	return e;
}
int main(void)
{
	int x, y, z;
	scanf_s("%d%d%d", &x, &y, &z);
	int a = max(x, y, z);
	printf("%d", a);
	return 0;
}