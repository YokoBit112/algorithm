#include <iostream>
#include <cmath>
using namespace std;

int n, q, a[1000001],b[1000001];
int main(void)
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int bi, ki;
	for (int i = 0; i < q; i++)
	{
		cin >> bi >> ki;
		b[max(0, bi - ki)]++;
		b[(min(bi + ki, 999999))]--;
	}
	int res = 0;
	if (b[0] >= a[0])res++;
	for (int i = 1; i < n; i++)
	{
		b[i] += b[i - 1];
		if (b[i] >= a[i])res++;
	}
	cout << res;
	return 0;
}