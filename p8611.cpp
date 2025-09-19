#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,temp,head = 0,ans = 1,r = 0,l = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (i == 0){head = temp;continue;}
		if (abs(temp) > abs(head) && temp < 0)r++;
		if (abs(temp) < abs(head) && temp > 0)l++;
	}

	if (head > 0)
	{
		if (r != 0)ans = l + r + 1;
	}
	else {
		if (l != 0)ans = l + r + 1;
	}
	cout << ans << endl;
	return 0;
}