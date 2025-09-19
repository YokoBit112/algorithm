#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t,n,a[200010],tem;

int main(void)
{
	cin >> t;
	while (t--)
	{
		ll sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 2; i <= n; i += 2) {
			if (i + 1 <= n) {
				tem = a[i] - a[i - 1] - a[i + 1];
				if (tem < 0) {
					sum -= tem;
					if (a[i + 1] >= -1 * tem)a[i + 1] += tem;
					else {
						tem += a[i + 1];
						a[i + 1] = 0;
						a[i - 1] += tem;
					}
				}
			}
			else {
				tem = a[i] - a[i - 1];
				if (tem < 0) {
					sum -= tem;
					a[i - 1] += tem;
					
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}