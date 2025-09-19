#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1001][1001],mod = 1e8+7;
int n, s, a, b;
int c(int x)
{
	return (x % n + n) % n;
}

int main(void)
{
	
	cin >> n >> s >> a >> b;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = (dp[i - 1][c(j - a * i)] + dp[i - 1][c(j + b * i)]) % mod;
	cout << dp[n - 1][c(s)];
}