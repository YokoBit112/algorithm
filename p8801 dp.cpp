#include <bits/stdc++.h>

using namespace std;

#define ll long long
int num[20];

string res;

void dps(int a, int b,int i,int n,string ans)
{
	if (i == n)
	{
		if (res < ans)res = ans;
		return;
	}
	int tempx = 9 - num[i], tempy = num[i] + 1;
	if (tempy <= b && tempx <= a)
	{
		ans[i] = '9';
		dps(a, b - tempy, i + 1, n, ans);
		dps(a - tempx, b, i + 1, n, ans);
	}
	else if (tempy <= b)
	{
		ans[i] = '9';
		dps(a, b - tempy, i + 1, n, ans);
	}
	else if (tempx <= a)
	{
		ans[i] = '9';
		dps(a-tempx, b, i + 1, n, ans);
	}
	else
	{
		ans[i] = num[i] + a + '0';
		dps(0, b, i + 1, n, ans);
	}
}

int main(void)
{
	string a;
	int e, b;
	cin >> a >> e >> b;
	int i = a.size();
	for (int p = 0; p < i; p++)num[p] = a[p] - '0';

	dps(e, b, 0, i,a);
		
	cout << res;
	cout << endl;
	return 0;
}