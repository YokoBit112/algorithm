#include <bits/stdc++.h>

using namespace std;

#define ll long long

//两式相加
string addstr(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0,jw = 0;
	while (a.size() > i && b.size() > i)
	{
		a[i] += b[i] - 2 * '0'+jw;
		jw = a[i] / 10;
		a[i] = (a[i] % 10) + '0'; i++;
	}
	while (a.size()>i)
	{
		a[i] += jw -  '0' ;
		jw = a[i] / 10;
		a[i] = (a[i] % 10) + '0'; i++;
	}
	while (b.size() > i)
	{
		b[i] += jw - '0';
		jw = b[i] / 10;
		a.push_back((b[i] % 10) + '0');
		i++;
	}
	while (jw)
	{
		a.push_back(jw % 10 + '0');
		jw /= 10;
	}
	reverse(a.begin(), a.end());
	return a;
}

//两式相乘
string prestr(string a, int b)
{
	reverse(a.begin(), a.end());
	int jw = 0;
	for (int i = 0; i<a.size(); i++) {
		a[i] = (a[i] - '0') * b+jw;
		jw = a[i] / 10;
		a[i] = (a[i] % 10) + '0';
	}
	while (jw)
	{
		a.push_back(jw % 10 + '0');
		jw /= 10;
	}
	reverse(a.begin(), a.end());
	return a;
}

string ccstr(string a, int b, int n)
{
	for (int i = 0; i < n; i++)
	{
		a = prestr(a, b);
	}
	return a;
}

int n;
string bx;

int main(void)
{
	cin >> n >> bx;
	string cx = ccstr("2", 2, n - 1), res;
	int be = 0;
	for (int i = 0; i < bx.size(); i++)
	{
		if (bx[i] >= '0' && bx[i] <= '9')
		{
			if (be)be++;
			res = addstr(prestr(cx, bx[i] - '0'), res);
			res.push_back('0');
		}
		else be = 1;
	}
	if (!be)res.pop_back();
	while (be)
	{
		if (be == 1)
		{
			if (*(res.end() - 1) >= '5')
			{
				res.pop_back();
				res = addstr(res, "1");
			}
			else res.pop_back();
		}
		else res.pop_back();
		be--;
	}
	cout << res;
}