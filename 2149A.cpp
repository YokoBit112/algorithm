#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[3];
int t;
int n;

int main(void) {
	cin >> t;
	while (t--) {
		cin >> n;
		int temp;
		while (n--) {
			cin >> temp;
			a[temp + 1]++;
		}
		cout << (a[0] % 2) * 2 + a[1] << endl;
		a[0] = 0; a[1] = 0; a[2] = 0;
	}
}