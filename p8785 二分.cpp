#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, m;

struct pa
{
	ll x, y, r;
	bool pd;
};

bool cmp(pa a, pa b)
{
	return a.x < b.x;
}

pa le[500005],pl;

ll ans;

void bfs(pa dat)
{
	if (ans >= n)return;
	dat.pd = 1;
	ll l = 0, r = n-1, Lm = 0,Rm = 0;
	while (l <= r)
	{
		Lm = (l + r) >> 1;
		if (le[Lm].x < dat.x - r)l = Lm + 1;
		else r = Lm - 1;
	}
	Lm = l;
	l = 0; r = n - 1;
	while (l <= r)
	{
		Rm = (l + r) >> 1;
		if (le[Lm].x <= dat.x + r)l = Rm + 1;
		else r = Rm - 1;
	}
	for (Lm; Lm <= Rm; Lm++)
	{
		if (le[Lm].pd)continue;
		if ((le[Lm].x - dat.x) * (le[Lm].x - dat.x) + (le[Lm].y - dat.y) * (le[Lm].y - dat.y) <= dat.r * dat.r) {
			le[Lm].pd = 1;
			ans++;
			bfs(le[Lm]);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> le[i].x >> le[i].y >> le[i].r;
	}
	sort(le, le + n, cmp);
	for (int i = 0; i < m; i++)
	{
		cin >> pl.x >> pl.y >> pl.r;
		bfs(pl);
	}
	cout << ans;
}