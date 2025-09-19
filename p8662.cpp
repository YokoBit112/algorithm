#include <bits/stdc++.h>

using namespace std;
int n,sum,ans;
char mapp[1001][1001];
int dex[] = {1,-1,0,0}, dey[] = {0,0,1,-1},t = 0;
void bfs(int x,int y)
{
	if (!t)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (mapp[x - dex[i]][y - dey[i]] != '.')
				cnt++;
		}
		if (cnt == 4)
		{
			ans++; t = 1;
		}
	}
	mapp[x][y] = '*';
	for (int i = 0; i < 4; i++)
	{
		if (mapp[x - dex[i]][y - dey[i]] == '#')
			bfs(x - dex[i], y - dey[i]);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < n; p++)
		{
			cin >> mapp[i][p];
		}
	}
	for (int i = 1; i < n-1; i++)
	{
		for (int p = 1; p < n-1; p++)
		{
			if (mapp[i][p] == '#')
			{
				sum++;
				t = 0;
				bfs(i, p);
			}
		}
	}
	cout << sum - ans;
}