#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	while (1)
	{
		int n = 0; scanf(" %d", &n);
		n /= 10;
		switch (n) {
		case 6:printf("D\n"); break;
		case 7:printf("C\n"); break;
		case 8:printf("B\n"); break;
		case 9:printf("A\n"); break;
		case 10:printf("A\n"); break;
		default:printf("E\n"); break;
		}
	}
	return 0;
}
