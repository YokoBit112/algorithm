#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;
#define ll long long
unordered_map<char, ll> hash1;
char c;
int main(void)
{
	printf("����������");
	while (c != '\n')
	{
		scanf("%c", &c);
		hash1[c]++;
	}
	printf("������Ҫ���ҵ��ַ���");
	scanf("%c", &c);
	printf("�ַ�%c�������еĸ���Ϊ%lld",c, hash1[c]);
}