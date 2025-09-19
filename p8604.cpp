#include <bits/stdc++.h>

using namespace std;

vector<int> tree[1001];
bool ne[1001];
int cnt[1001], a, b,sum = 0,n,m;

void dfs(int now)
{
	if (now == b)
	{
		sum++;
		for (int i = 1; i <= n; i++)
		{
			if (ne[i])cnt[i]++;
		}
	}
	else {
		for (int i = 0; i < tree[now].size(); i++)
		{
			if (ne[tree[now][i]] == 0) {
				ne[tree[now][i]] = 1;
				dfs(tree[now][i]);
				ne[tree[now][i]] = 0;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cin >> a >> b;
	dfs(a);
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == sum)ans++;
	}
	if (ans > 0)cout << ans;
	else cout << -1;
	return 0;
}