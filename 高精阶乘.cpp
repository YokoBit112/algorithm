#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

string sum = "1",sum1 = "0";
string ajb(string a,string b)
{
	char temp1; int jin = 0;
	string g;
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
	return g;
}
string fact(string n)
{
	if (n == "1" || n == "0")return sum;
	string temp, temp1; ll ws = 0;
	for (int i = n.size() - 1; i >= 0; i--)
	{
		ll a = 0;
		for (int p = sum.size() - 1; p >= 0; p--)
		{
			temp.push_back((sum[p] - '0') * (n[i] - '0'));
		}
		for (int p = 0; p != temp.size(); p++)
		{
			temp[p] += a;
			a = temp[p] / 10;
			temp[p] = (char)((temp[p] % 10) + '0');
		}
		
		while (a != 0)
		{
			temp.push_back((char)(a % 10 + '0'));
			a /= 10;
		}
		for (int p = temp.size() - 1; p >= 0; p--)
		{
			temp1.push_back(temp[p]);
		}
		for (int i = 0; i < ws; i++)
		{
			temp1.push_back('0');
		}
		ws++;
		temp.clear();
		sum1 = ajb(sum1, temp1);
		temp1.clear();
	}
	sum = sum1;
	sum1 = "0";
	n[n.size() - 1]--;
	
	if (n[n.size() - 1] < '0')
	{
		for (int i = n.size() - 2; i >= 0; i--)
		{
			
			if (n[i] > '0') {
				n[i]-=1;
				break;
			}
			else {
				n[i] = '9';
			}
		}
		if (n.size() != 1)
		{
			if (n[0] == '0')n = n.substr(1, n.size() - 1);
			n[n.size() - 1] = '9';
		}
		else return sum;
	}
	return fact(n);
}
int main(void)
{
	string n;
	printf("请输入n值:");
	cin >> n;
	cout << n << "!的值：" << fact(n);
	return 0;
}