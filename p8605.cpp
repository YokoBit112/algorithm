/*
#include <bits/stdc++.h>

using namespace std;

vector<int> cnet[100001];
int cnt;
void dfs(int head,int n,int a[],int fat)
{
	if (n == 3){if (head != a[1] && head != a[2])cnt++;}
	else {
		a[n] = head;

		for (int i = 0; i < cnet[head].size(); i++)
		{
			if(cnet[head][i]!=fat)dfs(cnet[head][i], n + 1, a, head);
		}
	}
}

int main(void)
{
	int n, m, a[4] = { 0,0 };
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		cnet[u].push_back(v);
		cnet[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
	{
		dfs(i + 1, 0,a,-1);
	}
	cout << cnt;
}
*///´¿Ä£Äâ

#include <bits/stdc++.h>

using namespace std;

int a[100001], b[1000001], c[1000001];

int main(void)
{
	long long n, m,cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i] >> c[i];
		a[b[i]]++;
		a[c[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		if (a[b[i]] > 1 && a[c[i]] > 1)
		{
			cnt += (a[b[i]] - 1) * (a[c[i]] - 1) * 2;
		}
	}
	cout << cnt;
	return 0;
}