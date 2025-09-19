#include <bits/stdc++.h>

using namespace std;

#define ll long long

int num[20];

int main(void)
{
	string a;
	int e, b;
	cin >> a >> e >> b;
	int i = a.size();
	for (int p = 0; p < i; p++)num[p] = a[p]-'0';

	for (int p = 0; p < i; p++)
	{
		if ((num[p] + 1) % 10 <= b)
		{
			b -= ((num[p] + 1) % 10);
			num[p] = 9;
		}
		else
		{
			if (9 - num[p] <= e)
			{
				e -= (9 - num[p]);
				num[p] = 9;
			}
			else {
				num[p] += e;
				e = 0;
			}
		}
	}
	for (int p = 0; p < i; p++)
	{
		cout << num[p];
	}
	cout << endl;
	return 0;
}