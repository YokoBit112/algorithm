#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> xyz(10);
	int x1, x2, y1, y2,x,y;
	for (int i = 0;i < n;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		xyz[i].push_back(x1);
		xyz[i].push_back(y1);
		xyz[i].push_back(x2);
		xyz[i].push_back(y2);
		xyz[i].push_back(i + 1);
		xyz[i].push_back(i + 1);
	}
	int r = n+1;
	for (int i = 0;i < m;i++) {
		cin >> x >> y;
		int ans = 0,mak = 0;
		for (int p = 0;p < n;p++) {
			x1 = xyz[p][0];
			y1 = xyz[p][1];
			x2 = xyz[p][2];
			y2 = xyz[p][3];
			//cout << x1 << "," << y1 << " " << x2 << "," << y2 << endl;
			int k = xyz[p][4],tc = xyz[p][5];
			if (x1 <= x && y1 <= y && x2 >= x && y2 >= y) {
				if (tc >= mak) {
					ans = k;
					mak = tc;
				}
			}
		}
		if (ans) {
			cout << ans << endl;
			xyz[ans - 1][5] = r++;
			
		}
		else cout << "IGNORED" << endl;
	}
	return 0;
}