#include <bits/stdc++.h>

using namespace std;
int a[100001],n,q;

int left(int fin) {
	int l = 0, r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (a[mid] < fin) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l + 1; 
}
int right(int fin) {
	int l = 0, r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (a[mid] <= fin) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l + 1;
}

int main(void)
{
	
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int fin;
	for (int i = 0; i < q; i++)
	{
		cin >> fin;
		cout << left(fin) << " " << right(fin) << endl;
	}
	return 0;
}