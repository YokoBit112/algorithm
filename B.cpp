#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n, m, t;
char a;
bool lis;
bool lisx[51], lisy[51];
int main(void)
{
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		lis = 0;
		cin >> n >> m;
		memset(lisx, 0, sizeof(lisx));
		memset(lisy, 0, sizeof(lisy));
		for (int i = 0; i < n; i++)
		{
			for (int p = 0; p < m; p++)
			{
				cin >> a;
				if (a == '1')
				{
					if (lisx[i] == 1&&lisy[p] == 1)
					{
						lis = 1;
					}
					
				}
				else {
					lisx[i] = 1;
					lisy[p] = 1;
				}
			}
		}
		if (lis)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}