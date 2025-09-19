#include <bits/stdc++.h>

using namespace std;
bool a[100001];
int main(void)
{
	int k;
	cin >> k;
	int n, m = 0;
	while(cin >> n)
	{
		if (a[n] == 0)a[n] = 1;
		else m = n;
	}
	for (int i = 1;i < 100001; i++)
	{
		if (a[i] == 0&&a[i+1]&&a[i-1]) {
			n = i; break;
		}
	}
	cout << n << " " << m << endl;
	return 0;

}
