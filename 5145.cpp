#include <bits/stdc++.h>


using namespace std;
#define ll long long

int w[1001][10], tem, n, m;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p < m; p++) {
			cin >> tem;
			w[i][p] = tem;
		}
	}

	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int p = n-1; p >=0; p--) {
			if (i == p)continue;
			bool se = 0;
			for (int q = 0; q < m; q++) {
				if (w[i][q] >= w[p][q])
				{
					se = 1;
					break;
				}
			}
			if (!se) {
				res = p + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}