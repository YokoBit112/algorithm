#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ll long long
using namespace std;
char a[100000001],c;
ll sum;
int main(void)
{
	printf("���������飺");
	ll i = 0;
	while (c != '\n')
	{
		scanf("%c", &c);
		a[i++] = c;
	}i = 0;
	printf("�������ַ�:");
	scanf("%c", &c);
	while (a[i] != '\n') {
		if (a[i++] == c)sum++;
	}
	printf("�ַ�'%c'�������еĸ���Ϊ:%lld",c, sum);
}