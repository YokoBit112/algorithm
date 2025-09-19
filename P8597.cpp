#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string a, b;
	int cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			b[i] = (b[i] == '*') ? 'o' : '*';
			b[i+1] = (b[i+1] == '*') ? 'o' : '*';
			cnt++;
		}
	}
	cout << cnt;
	return 0;

}