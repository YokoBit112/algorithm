#include <iostream>
using namespace std;
int a[1002][1002],n, m, p[5];
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i != m; i++)
	{
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		for (int l = p[0]; l <= p[2]; l++)
			for (int q = p[1]; q <= p[3]; q++)
				a[l][q]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int p = 1; p <= n; p++)cout << a[i][p] << " ";
		cout << endl;
	}
	return 0;
}