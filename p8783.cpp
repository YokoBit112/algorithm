#include <iostream>

using namespace std;

#define ll long long

ll n, m, k,ans;

int a[510][510],b[510];

int main(void)
{
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++)
	{
		for (int p = 1;p <= m;p++)
		{
			cin >> a[i][p];
		}
	}
	for (int p = 1;p <= m;p++)
	{
		for (int i = 1;i <= n;i++)
		{
			a[i][p] += a[i-1][p];
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int p = i;p <= n;p++)
		{
			for (int j = 1;j <= m;j++)
			{
				b[j] = a[p][j] - a[i-1][j];
			}
			int l = 1, r = 1;ll now = 0;
			for (r;r <= m;r++)
			{
				now += b[r];
			if (now <= k)
			{
				ans += (ll)r - l + 1;
			}
			else
			{
				while (now > k)
				{
					now -= b[l++];
				}
				ans += (ll)r - l + 1;
			}
			}

		}
	}
	cout << ans << endl;
}