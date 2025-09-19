#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n, room[21];
bool gx[21][21],bj[21];

ll maxx = 0;
string res;

void bfs(int k,ll val,string lis)
{
	bj[k] = 1;
	if (lis.size())lis.push_back(' ');
	lis.append(to_string(k+1));
	val += room[k];
	for (int i = 0; i < n; i++)
	{
		if (gx[k][i] == 1&&!bj[i])bfs(i, val, lis);
		else {
			if (maxx < val) { maxx = val; res = lis; }
		}
	}

	if (k == n - 1)
	{
		if (maxx < val)
		{
			maxx = val; res = lis;
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> room[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int p = i+1; p < n; p++)
		{
			cin >> gx[i][p];
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	for (int p = 0; p < n+1; p++)
	//	{
	//		cout << gx[i][p];
	//	}
	//	cout << endl;
	//}
	for (int i = 0; i < n; i++)
	{
		memset(bj, 0, sizeof(bj));
		bfs(i, 0, "");
	}
	cout << res << endl << maxx;
}