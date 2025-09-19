#include<iostream>
#include<cstdio>
using namespace std;
int n, m, ans;
int gj[401], jq[21][21], tim[21][21],jgsx[405],sum,lasr[21];
bool vis[25][10005];
int main()
{
	cin >> m >> n;
	for (int i = 0; i != n * m; i++)cin >> gj[i];
	for (int i = 0; i != n; i++) { for (int p = 0; p != m; p++) { cin >> jq[i][p]; } }
	for (int i = 0; i != n; i++) { for (int p = 0; p != m; p++) { cin >> tim[i][p]; } }
	for (int i = 0; i != n*m; i++)
	{
		int s = gj[i] - 1;
		int who = jq[s][jgsx[s]], time = tim[s][jgsx[s]],res = 0;
		jgsx[s]++;
		int p = lasr[s];
		while (res != time) {
			if (vis[who][p])res = 0;
			else res++;
			p++;
		}
		int temp = p;
		for (p = temp -time; p < temp; p++)
		{
			vis[who][p] = 1;
		}
		lasr[s] = temp;
		sum = max(sum, lasr[s]);
	}
	cout << sum << endl;
	return 0;
}