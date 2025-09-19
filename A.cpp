#include <bits/stdc++.h>

using namespace std;
#define ll long long
bool lis[1001];
int main(void)
{
	int t;
	cin >> t;
	ll x, y, a;
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y >> a;
		a = (a) % (x + y);
		if (x - a <= 0)lis[i] = 1;
		else lis[i] = 0;
	}
	for (int i = 0; i < t; i++)
	{
		if (lis[i])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}