#include <bits/stdc++.h>

using namespace std;
int a[] = {1,2,3,4,5,6,7,8,9};

long long pd(int l, int r)
{
	int f = 1, res = 0;
	for (int i = r; i >= l; i--)
	{
		res += f * a[i];
		f *= 10;
	}
	return res;
}

int main(void)
{
	int n, res = 0;
	cin >> n;

	do{
		for (int i = 0; i < 7; i++)
		{
			int num = pd(0, i);
			if (num > n)break;
			for (int p = i+1; p < 8; p++)
			{
				if (pd(i+1, p) % pd(p+1, 8) == 0)
				{
					if (num + (pd(i+1, p) / pd(p+1, 8)) == n)res++;
				}
			}
			
		}
	}
	while(next_permutation(a, a + 9));
	cout << res << endl;
	return 0;
}