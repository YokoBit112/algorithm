#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, b[100001],m;



int main(void) {
	cin >> n;
	for (int i = 0;i < n;i++) {
		b[i] = 100001;
	}
	for (int i = 1;i <= n;i++) {
		cin >> b[i];
	}
	cin >> m;
	ll cas, a, e;
	ll ne = 1ll + sqrt(n);
	for (int i = 0;i < m;i++) {
		cin >> cas;
		if (!cas) {
			cin >> a >> e;
			b[a] = min(b[a], e);
		}
		else {
			cin >> a;
			ll lmin = max(a-ne-1,(ll)0), lmax = min(a + ne,n),mine = 1e9;
			for (int i = lmin;i <= lmax;i++) {
				mine = min(mine, (i - a) * (i - a) + b[i]);
			}
			cout << mine << endl;
		}
		return 0;
	}
}