#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long
int main(void)
{
	ll n, a = 0, b = 0,sum = 0,max = 0;
	scanf("%lld", &n);
	for (int i = 0; i != n; i++)
	{
		scanf("%lld", &b);
		if (a == 0 || b - a == 1)sum++;
		else{if (max < sum)max = sum;sum = 1;}a = b;
	}
	printf("%lld", max);
}