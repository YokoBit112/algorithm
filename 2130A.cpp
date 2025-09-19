#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void)
{
	int t, n,k;
	ll sum = 0;
	cin >> t;
	while (t--)
	{
		sum=0;
		cin >> n;
		for(int i = 0;i<n;i++)
		{
			cin >> k;
			sum += k + (k == 0);
		}
		cout << sum << endl;
	}
	return 0;
}
//记得逆推结论