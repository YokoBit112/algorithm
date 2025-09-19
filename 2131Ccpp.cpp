#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ll long long
map<ll, int> S, T;
int t,n;
ll k,tem;
int main(void)
{ 
	cin >> t;
	while (t--) {
		cin >> n >> k;
		bool ke = 1;
		ll r = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tem;
			r = tem % k;
			S[min(r,(k - r) % k)]++;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> tem;
			r = tem % k;
			S[min(r,(k - r) % k)]--;
		}
		for (auto& p : S) {
			if (p.second)ke = 0;
		}
		if (ke)cout << "YES" << endl;
		else cout << "NO" << endl;
		S.clear();
		T.clear();
	}
	return 0;
}