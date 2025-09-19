#include <iostream>
#include <string>
using namespace std;
int a[100001]; string b[100001];
int main(void)
{
	int n, m, case1, case2, ed = 0; cin >> n >> m;
	for (int i = 0; i != n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i != m; i++)
	{
		cin >> case1 >> case2;
		if (case1 == 0) {
			if (a[ed] == 0) {
				ed = (ed + n - case2) % n;
			}
			else {
				ed = (case2 + ed) % n;
			}
		}
		else {
			if (a[ed] == 0)
			{
				ed = (case2 + ed) % n;
			}
			else {
				ed = (ed + n - case2) % n;
			}
		}
	}
	cout << b[ed];
}