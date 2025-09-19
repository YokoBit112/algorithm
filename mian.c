#include <iostream>

using namespace std;

int main(void) {
	int t;
	if(!(cin >> t))return 0;
	while (t--) {
		long long n, m, k,ans,tot;
		cin >> n >> m >> k;
		tot = n * m;
		ans = tot - k + 1;
		if (ans>=0)
			cout << ans << endl;
		else cout << 0 << endl;
	}
	return 0;
}