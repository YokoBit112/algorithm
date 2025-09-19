#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
int mapp[51][51];
int cnt[51][51][13][13];
ll mod = 1e9 + 7;
ll dfs(int x, int y, int kx, int maxx)
{
	ll ans = 0;
	if (x > n || y > m)return 0;
	if (cnt[x][y][kx][maxx + 1] != -1)return cnt[x][y][kx][maxx + 1];
	if (x == n && y == m) {
		if(k == kx || (k - 1 == kx && mapp[x][y] > maxx))ans++;
	} 
	else
	{
		ans = (ans + dfs(x + 1, y, kx, maxx)) % mod;
		ans = (ans + dfs(x, y + 1, kx, maxx)) % mod;
		if (maxx < mapp[x][y]) {
			ans = (ans + dfs(x + 1, y, kx + 1, mapp[x][y])) % mod;
			ans = (ans + dfs(x, y + 1, kx + 1, mapp[x][y])) % mod;
		}
	}

	
	
	cnt[x][y][kx][maxx + 1] = ans % mod;
	return cnt[x][y][kx][maxx + 1];
}

int main(void)
{

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int p = 1; p <= m; p++)
		{
			cin >> mapp[i][p];
		}
	}
	memset(cnt, -1, sizeof(cnt));  //注意要初始化为-1
	cout << dfs(1, 1, 0, -1);
}