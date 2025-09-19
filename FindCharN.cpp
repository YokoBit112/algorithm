#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ll long long
using namespace std;
char a[100000001],c;
ll sum;
int main(void)
{
	printf("请输入数组：");
	ll i = 0;
	while (c != '\n')
	{
		scanf("%c", &c);
		a[i++] = c;
	}i = 0;
	printf("请输入字符:");
	scanf("%c", &c);
	while (a[i] != '\n') {
		if (a[i++] == c)sum++;
	}
	printf("字符'%c'在数组中的个数为:%lld",c, sum);
}