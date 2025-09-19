#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
long a[5000005], k;
void qs(long l, long r) {
	long s = l, e = r, mid = a[(l + r) / 2];
	do {
		while (a[e] > mid)e--;
		while (a[s] < mid)s++;
		if (s <= e)
		{
			swap(a[s], a[e]);
			s++; e--;
		}
	} while (s <= e);
	if (k <= e)qs(l, e);
	else if (k >= s)qs(s, r);
	else {
		cout << a[e+1];
		exit(0);
	}
}

int main(void)
{
	long n;
	scanf("%ld%ld", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%ld", &a[i]);
	}
	qs(0, n - 1);
	return 0;
}