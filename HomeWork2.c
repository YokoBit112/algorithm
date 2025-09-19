#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 0;
int sum = 1;
int fact(int n)
{
	if (n != num)
	{
		sum *= n++;
		fact(n);
	}
	else return sum * n;
}

int main(void)
{
	scanf("%d", &num);
	if (num == 0)printf("1");
	else printf("%d",fact(1));
}