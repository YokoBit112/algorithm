#include <iostream>
using namespace std;
int a[1010] = { 0 };
int main(void)
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) { cin >> n; a[n]++; }
	for (int i = 0; i < 1000; i++)while (a[i]--)cout << i << " ";
	return 0;
}