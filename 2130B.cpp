#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;
int n, s, a[3],sum,tem;

int main(void)
{
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		sum = 0;
		a[0] = a[1] = a[2] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tem;
			a[tem]++;
			sum += tem;
		}
		if (sum == s || sum + 2 <= s)cout << -1 << endl;
		else {
			for (int i = 0; i < a[0]; i++)cout << 0 << " ";
			for (int i = 0; i < a[2]; i++)cout << "2 ";
			for (int i = 0; i < a[1]; i++)cout << "1 ";
			cout << endl;
		}
	}
}