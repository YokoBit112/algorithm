#include <iostream>

using namespace std;
int b[1000001],c[1000001];
int main(void)
{
	int n,s;
	cin >> n;
	for (int i = 0; i != n; i++)
	{
		cin >> s;
		b[s+1]--;
	}
	c[0] = n;
	long long max = 0; int q = 0;
	for (int i = 1;c[i-1]!=0; i++)
	{
		c[i] = c[i - 1] + b[i];
		if (max < (long long)c[i] * i) {
			max = (long long)c[i] * i; q = i;
		}
	}
	cout << max <<" "<<q;
	return 0;
}