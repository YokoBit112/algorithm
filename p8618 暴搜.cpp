#include <bits/stdc++.h>
#include <unordered_map>
#include <cmath>
using namespace std;

#define ll long long
unordered_map<int, ll> hashh;
int main(void)
{
	int n, m;
	ll sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> hashh[i];
		sum += hashh[i];
	}
	ll l, r,tem;
	while (m--)
	{
		cin >> l >> r;
		while (l <= r)
		{
			if (hashh[l] <= 2);
			else {
				tem = ((int)log2(hashh[l]) + 1);
				sum -= hashh[l] - tem;
				hashh[l] = tem;
			}
			l++;
		}
		cout << sum << endl;
	}
}