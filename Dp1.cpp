#include <iostream>

using namespace std;

int n, a[122][122] = { 0 }, max1 = 0, temp[122][122] = { 0 }, arr2[122] = { 0 };


int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int p = 1; p <= n; p++)
		{
			cin >> a[i][p];
			temp[i][p] = a[i][p] + temp[i - 1][p];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int p = i; p <= n; p++)
		{
			for (int q = 1; q <= n; q++)
			{
				arr2[q] = temp[p][q] - temp[i - 1][q];
			}
			for (int q = 1; q <= n; q++)
			{
				int temp1 = 0;
				for (int l = q; l <= n; l++)
				{
					temp1 += arr2[l];
					if (max1 < temp1)max1 = temp1;
				}
			}
		}
	}
	cout << max1;
	return 0;
}
