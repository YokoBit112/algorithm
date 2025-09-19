#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, val[20], kal[20];
int main(void)
{
	cin >> t;
	int cas;
	kal[0] = 3;
	for (int i = 1; i < 20; i++)
	{
		kal[i] = pow(3, i + 1) + i * pow(3, i - 1);
	}
	while (t--) {
		cin >> n;
		int k = 0;
		ll sum = 0;
		while (n)
		{
			cas = n % 3;
			n /= 3;
			sum += cas * kal[k++];
		}
		cout << sum << endl;
	}
	return 0;
}