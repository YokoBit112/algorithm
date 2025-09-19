#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m;
int l[50001][3], pl[500001][3];
bool bj[50001];
ll res;
void bfs(int dat[])
{
	int x = dat[0], y = dat[1], r = dat[2];
	for (int i = 0; i < n; i++)
	{
		if (bj[i])continue;
		if ((x - l[i][0]) * (x - l[i][0]) + (y - l[i][1]) * (y - l[i][1]) <= r*r)
		{
			bj[i] = 1;
			res++;
			bfs(l[i]);
		}
	}
}
int main(void)
{
	cin >> n >> m;
	int x, y, r;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i][0] >> l[i][1] >> l[i][2];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> pl[i][0] >> pl[i][1] >> pl[i][2];
		bfs(pl[i]);
	}
	cout << res;
}