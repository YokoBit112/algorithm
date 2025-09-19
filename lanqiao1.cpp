#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int a[101], n, k, sum1, sum2, max1, max2, count1, temp, b[102], c[101];
bool asd;

int main(void)
{
	cin >> n; for (int i = 0; i != n; i++)
	{
		cin >> a[i];
	}
	if (n == 1)count1 = 0;
	else {
		for (int x = 1; x != n; x++)
		{
			max1 = 0;
			for (int maxP = 0; maxP < x; maxP++)
			{
				if (a[maxP] <= a[x])continue;
				sum1 = 1; int f = 1; b[0] = a[maxP];
				for (int i = 0; i < x; i++) {
					if (a[i]<a[maxP] && a[i]>a[x])
					{
						if (b[f - 1] > a[i])
						{
							b[f] = a[i]; f++;
							sum1++;
						}
						else if (a[i] > b[f - 1])
						{
							asd = true;
							for (int p = 1; p != f; p++)
							{
								if (a[i] < b[p]) { asd = false; break; }
							}
							if (asd)b[f] = a[i];
						}
					}
				}
				if (sum1 > max1)max1 = sum1;
			}
			max2 = 0;
			for (int MaxE = n - 1; MaxE > x; MaxE--)
			{
				if (a[MaxE] <= a[x])continue;
				sum2 = 1; int f = 1; c[0] = a[MaxE];
				for (int i = n - 1; i > x; i--) {
					if (a[i]<a[MaxE] && a[i]>a[x])
					{
						if (c[f - 1] > a[i])
						{
							c[f] = a[i]; f++;
							sum2++;
						}
						else if (a[i] > c[f - 1])
						{
							asd = true;
							for (int p = 1; p != f; p++)
							{

								if (a[i] < c[p]) { asd = false; break; }
							}
							if (asd)c[f] = a[i];
						}
					}
				}
				if (sum2 > max2)max2 = sum2;
			}
			if (sum1 == 0 || sum2 == 0)temp = 0;
			else temp = sum1 + sum2 + 1;
			cout << sum1 << "  " << sum2 << endl;
			if (temp > count1)count1 = temp;
		}

	}
	cout << count1;
	return 0;
}