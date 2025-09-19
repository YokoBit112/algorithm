#include <bits/stdc++.h>

using namespace std;

struct edge{
	int  note,dir;
};
vector<edge> tree[100001];
int mdir[100001];

void dfs(int node, int father, int dir)
{
	mdir[node] = dir;
	for (int i = 0; i < tree[node].size(); i++)
	{
		if (tree[node][i].note != father) {
			dfs(tree[node][i].note, node, dir + tree[node][i].dir);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	dfs(1, -1, 0);
	int td = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mdir[i] > mdir[td])
		{
			td = i;
		}
	}
	dfs(td, -1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (mdir[i] > mdir[td])
		{
			td = i;
		}
	}
	long long s = mdir[td];
	s = 10 * s + s * (s + 1) / 2;
	cout << s;
	return 0;
}