#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000001],b[1000001];
int n, m;
ll sum;

ll finde(int k) {
	return sum-b[k-2];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> m;
	int cas, nu;
	for (int i = 1;i < n;i++) {
		b[i-1] = a[i-1] - a[i];
		sum += b[i-1];
	}
	sort(b, b + n,greater<int>());
	for (int i = 1;i < n;i++) {
		b[i] += b[i - 1];
	}
	for (int i = 0;i < m;i++) {
		cin >> cas >> nu;
		if (!cas) {
		}
		else {
			cout << finde(nu) << endl;
		}
	}
}