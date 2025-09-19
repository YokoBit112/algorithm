#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct pa
{
	ll t = 0, h = 0;
};

pa a[1000001], c[1000001];

void msort(int l,int r)
{
	if (l == r)return;
	ll mid = (l + r) >> 1, i = l, j = mid + 1, k = l;
	msort(l, mid); msort(mid + 1, r);
	while (i <= mid && j <= r)
	{
		if (a[i].h <= a[j].h)
		{
			a[i].t += j-mid-1;
			c[k++] = a[i++];
		}
		else {
			a[j].t += mid + 1 - i;
			c[k++] = a[j++];
		}
	}
	while (j<=r){
		c[k++] = a[j++];
	}
	while (i <= mid)
	{
		a[i].t += j - mid -1;
		c[k++] = a[i++];
	}

	for (int p = l; p <= r; p++)
	{
		a[p] = c[p];
	}
}

int main(void)
{
	ll n,ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].h;
	}
	msort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		ans += a[i].t * (a[i].t + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}