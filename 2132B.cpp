#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, m,k,val;
ll listr[1000000];
int main(void)
{
	cin >> m;
	while (m--)
	{
		int lis = 0;;
		cin >> n;
		k = 1000000000000000001;
		val = 900000000000000000;
		while (k>10) {
			if (!(n % k))listr[lis] = n / k, ++lis;
			k -= val;
			val /= 10;
		}
		cout << lis << endl;

			for (int i = 0; i < lis; i++)
			{
				cout << listr[i] << " ";
			}
		if(lis)cout << endl;
	}
	return 0;
}