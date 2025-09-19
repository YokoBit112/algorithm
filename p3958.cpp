#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define ll long long
struct pa {
	ll x, y, z;
};
pa a[101];
bool bj[101],res = 0;
ll t, n, h, r;

bool dis(ll x1, ll x2, ll y1, ll y2, ll z1, ll z2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= 4 * r * r;
}

void bfs(int k)
{
	bj[k] = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == k)continue;
		if (dis(a[i].x, a[k].x, a[i].y, a[k].y, a[i].z, a[k].z)&&!bj[i])
		{
			bfs(i);
		}
	}
	if (a[k].z + r >= h)res = 1;
	
}

int main(void)
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		cin >> n >> h >> r;
		memset(bj, 0, sizeof(bj));
		
		for (int p = 0; p < n; p++)
		{
			cin >> a[p].x >> a[p].y >> a[p].z;
		}
		res = 0;
		for (int p = 0; p < n; p++)
		{
			if (a[p].z <= r)
			{
				
				bfs(p);
				
			}
		}
		if (res)cout << "Yes" << endl;
		else cout << "No"<<endl;
	}
}