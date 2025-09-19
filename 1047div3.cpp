#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t,n,p[200001];

map<int,int> hash1;
int main(void) {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			cout << n - p[i] + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}