#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, u, v;
vector<int> lis[200001],lisd;

int main(void) {
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i <= n; i++) lis[i].clear();

		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			lis[u].push_back(v);
			lis[v].push_back(u);
		}
		if (n <= 3){cout << 0 << endl; continue;}
		int head_max = 0, head = 0;
		int res = 0,sum1 = 0,sumx = 0;
		
		for (int i = 1; i <= n; i++) {
			if (lis[i].size() == 1)sum1++;
		}
		for (int i = 1; i <= n; i++) {
			int temp = 0;
			for (int p = 0; p < lis[i].size(); p++) {
				if (lis[lis[i][p]].size() == 1)temp++;
			}
			if (sumx < temp)sumx = temp;
		}
		cout << sum1 - sumx << endl;
	}
	return 0;
}