#include <iostream>
using namespace std;

const int mode = 1e9 + 7,ne = 1e7;

int main(void)
{
	int a[ne] = { 0,1,2,5 };
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i++)
	{
		a[i] = (2 * a[i - 1]%mode + a[i - 3])%mode;
	}
	printf("%d", a[n]);
	return 0;
}