#include <iostream>
#define ll long long
using namespace std;

ll a[5000002],d[5000002];

int main(void)
{
	ll n, p, min = 1e9;
	cin >> n >> p;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 0; i != p; i++)
	{
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		d[x] += z; d[y + 1] -= z;
	}
	
	for (int i = 1; i <= n; i++)
	{
		a[i] = d[i] + a[i - 1];
		if (a[i] < min)min = a[i];
	}
	cout << min;
}
//for (int p = x - 1; p != y; p++)a[p] += z;