#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int factorsum(int i) {
	if (i == 1)return 0;
	int temp = i / 2, sum = 0;
	for (int s = 2; s <= temp; s++)
	{
		if (i % s == 0)sum += s;
	}
	return sum+1;
}

int main(void)
{
	int m, n;
	printf("输入两个正整数m和n（1<=m<=n<=10000)：");
	scanf("%d%d", &m, &n);
	printf("从%d项到%d项的所有的完数是：\n", m, n);
	for (int i = m; i <= n; i++)
	{
		if(i == factorsum(i))
		printf("%d ", i);
	}
	return 0;
}