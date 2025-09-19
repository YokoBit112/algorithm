#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0,b = 0;
	scanf("%d%d", &a, &b);
	int* c = &a, * d = &b;
	int temp = *c;
	*c = *d;
	*d = temp;
	printf("%d  %d", a,b);
}