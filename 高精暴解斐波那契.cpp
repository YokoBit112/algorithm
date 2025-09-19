#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#define ll long long
int n, m,l = 2;
std::string a = "1", b = "1", g;
std::string fib(int na)
{
	if (na < 3)return b;
	while (l != na)
	{
	l++;
	char temp1; int jin = 0;
	int p = std::max(a.size(), b.size());
	bool as = true, bs = true;
	auto e = a.end() - 1;
	auto f = b.end() - 1;
	int d = 0;
	for (int i = 0; i < p; i++)
	{
		if (as && bs) {
			char tem = *e + *f - '0' + d; if (e != a.begin())e--; else as = false; if (f != b.begin()) f--; else bs = false;
			if (tem - '0' > 9) { tem -= 10; d = 1; }
			else d = 0;
			g.push_back(tem);
		}
		else if (!as)
		{
			if (d == 0)
				g.push_back(*f);
			else {
				if (*f + 1 - '0' > 9) {
					g.push_back(*f - 9); d = 1;
				}
				else {
					g.push_back(*f + 1); d = 0;
				}
			}
			if (f != b.begin())
				f--;
		}
		else if (!bs) {
			if (d == 0)
				g.push_back(*e);
			else {
				if (*e + 1 - '0' > 9) {
					g.push_back(*e - 9); d = 1;
				}
				else {
					g.push_back(*e + 1); d = 0;
				}
			} if (e != a.begin())e--;
		}
	}
	if (d == 1)g.push_back('1');
	std::string se;
	for (int i = g.size() - 1; i >= 0; i--)
	{
		se.push_back(g[i]);
	}
	g = se; se.clear();
	a = b; b = g; g.clear();
	}
	return b;
}

int main(void)
{
	printf("输入两个正整数m和n（1<=m<=n<=10000：");
	scanf("%d%d", &m, &n);
	printf("从%d项到%d项的Fibonacci数是：\n",m,n);
	for (int i = m; i <= n; i++)
	{
		std::cout << fib(i)<<" ";
	}
	return 0;
}