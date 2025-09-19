#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, m;
int a[200001], b[200001];
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll l = 0, r = 4e10, mid, sum;
	bool bj = 0;
	while (l < r)
	{
		sum = 0;
		bj = 0;
		mid = (l + r) >> 1;

		for (int i = 0; i < n; i++)
		{
			if (mid > a[i])sum += mid - a[i];
			if (mid - a[i] > b[i])bj = 1;
		}
		if (sum > m)r = mid;
		else {
			if (bj)r = mid;
			else l = mid + 1;
		}
	}
	cout << l-1 << endl;
}