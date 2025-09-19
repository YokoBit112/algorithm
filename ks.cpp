#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<bool> s;

int sn[300001],sz[300001];

int main(void) {
	int n;
	cin >> n;
	int a,cnt = 0;
	set<int> sf;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push_back(a);
		if (a == 1) {
			cnt++; sn[i+1]++;
		}
		else {
			sz[i + 1]++;
		}
	}
	for (int i = 1; i <= n+1; i++)
	{
		sn[i] += sn[i - 1];
		sz[i] += sz[i - 1];
	}
	sf.insert(cnt);
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int p = i; p <= n; p++)
		{
			int temp = cnt;
			temp += sz[p] - sz[i-1];
			temp -= sn[p] - sn[i-1];
			if (sf.find(temp) == sf.end())
			{
				res++;
				sf.insert(temp);
			}
		}
	}
	cout << res << endl;

	return 0;
}