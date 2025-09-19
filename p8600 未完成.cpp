#include <bits/stdc++.h>

using namespace std;

int tree[50001];
int cnt;
void dfs(int s,int cot)
{
	if (tree[s] - 1 == s || tree[s] + 1 == s)
	{
		dfs(tree[s],cot+1);
		cnt+=cot;
	}
}

int main(void) {
	int n;
	cin >> n;
	int a, b = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		tree[a] = b;
		b = a;
	}
	cnt = n;
	for (int i = 2; i <= n; i++)
	{
		dfs(i, n);
	}
	cout << cnt-1;
}