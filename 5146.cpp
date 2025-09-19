#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
int k, q, ke;
bool vis[100000001];
ll prime[6000000];
void euler(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (!vis[i])prime[++ke] = i;
		for (ll j = 1; j <= ke; j++) {
			if (prime[j] * i > n)break;
			vis[prime[j] * i] = true;
			if (i % prime[j] == 0)break;
		}
	}
}



int main(void) {
	cin >> q;
	euler((ll)100000);
	while (q--) {
		cin >> n >> k;
		ll tem = n;
		int i = 1,rs = 0;
		while (tem > 1&&i<=ke) {
			if (!(tem % prime[i]))
			{
				tem /= prime[i];
				rs++;
			}
			else {
				//if (rs)cout << prime[i] << " " << rs << endl;
				if (rs&&rs<k) {
					n /= pow(prime[i], rs);
				}
				rs = 0;
				i++;
			}
		}
		if (rs && rs < k) {
			
			n /= pow(prime[i],rs);
		}
		if (tem == n)cout << 1 << endl;
		else cout << n/tem << endl;
	}
	
}
