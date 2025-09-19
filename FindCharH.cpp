#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;
#define ll long long
unordered_map<char, ll> hash1;
char c;
int main(void)
{
	printf("请输入数组");
	while (c != '\n')
	{
		scanf("%c", &c);
		hash1[c]++;
	}
	printf("请输入要查找的字符：");
	scanf("%c", &c);
	printf("字符%c在数组中的个数为%lld",c, hash1[c]);
}