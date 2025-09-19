#include <bits/stdc++.h>

using namespace std;

int n, k,ads,res;
int cd[100010][2];

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> cd[i][0] >> cd[i][1];
	}
	int l = 1, r = 100000, mid, sum ;
	while (l < r)
	{
		sum = 0;
		mid = (l + r + 1)/2;
		for (int i = 0; i < n; i++)
		{
			sum += (cd[i][0]/mid) * (cd[i][1] / mid);
		}
		if (sum < k)r = mid-1;
		else l = mid;
	}
	cout << l;
	return 0;
}