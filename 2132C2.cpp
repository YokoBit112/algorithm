#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,ki[42];
ll k, n,sk[41],sum;


int main(void) {
	cin >> t;
	ll c = 3,cnt = 1;
	for (int i = 0; i < 21; i++) {
		sk[i] = c;
		c = c * 3 + cnt;
		cnt *= 3;
	}
	while (t--) {
		cin >> n >> k;
		sum = 0;
		if (n == 1) { cout << 3 << endl; continue; }
		int p = 0,ml = 0;
		while (n) {
			ki[p++] = n % 3;
			ml += n % 3;
			n /= 3;
		}
		if (ml > k) {cout << -1 << endl; continue;}
		ml = (k - ml)/2;
		for (int i = p - 1; i >= 1; i--) {
			if (ki[i] <= ml) {
				ki[i - 1] += 3 * ki[i];
				ml -= ki[i];
				ki[i] = 0;
			}
			else {
				ki[i - 1] += ml * 3;
				ki[i] -= ml;
				break;
			}
		}
		for (int i = 0; i < p; i++)
		{
			//cout << i << "  " << ki[i] << "  " << endl;;
			sum += ki[i] * sk[i];
		}
		cout << sum << endl;
		memset(ki, 0, sizeof(ki));
	}
	return 0;
}