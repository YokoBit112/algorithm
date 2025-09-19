#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll a[500001],c[500001],ans = 0;

void msort(ll l,ll r)
{
	if (l == r)return;
	ll mid = (l + r) / 2,i = l,j = mid+1,k = l;
	msort(l, mid); msort(mid + 1, r);
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
		{
			c[k++] = a[i++];
		}
		else {
			c[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
	while (i <= mid)
	{
		c[k++] = a[i++];
	}
	while (j<=r)
	{
		c[k++] = a[j++];

	}
	for (ll q = l; q <= r; q++)
	{
		a[q] = c[q];
	}
}

int main(void)
{
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	msort(0, n - 1);
	cout << ans << endl;
	return 0;
}