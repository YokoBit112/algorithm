#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<ll>arr(k);
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	for (ll a : arr) {
		if (a > n) break;
		n -= a;
		ans++;
	}
	cout << ans;
	return 0;
}