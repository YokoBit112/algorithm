#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k, l, a[1010][1010],b[1010][1010];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k >> l;
	for (int i = 1;i <= n;i++) {
		for (int p = 1;p <= m;p++) {
			cin >> a[i][p];
		}
	}
	ll sum = 0;
	for (int i = 1;i <= n;i++) {
		for (int p = 1;p <= m;p++) {
			a[i][p] = a[i][p] + a[i - 1][p] + a[i][p - 1] - a[i - 1][p - 1];
		}
	}
	for (int i = 1;i <= k;i++) {
		for (int p = 1;p <= l;p++) {
			int x1 = i, y1 = p,x2 = x1+(n-k),y2 = y1+(m-l);//O(n-k+1,m-l+1)
			ll temp = a[x2][y2] + a[x1-1][y1-1] - a[x2][y1 - 1] - a[x1-1][y2];
			sum += llabs(temp);
		}
	}
	cout << sum;
	return 0;
}
//5 5 3 3
//0 -1 -1 0 0
//0 1 -1 2 -2
//2 -2 2 2 0
//-1 0 0 -2 -1
//0 -2 0 1 1