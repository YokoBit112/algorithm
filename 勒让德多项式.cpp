#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ll long long 
using namespace std;

double fun(ll n, double x)
{
	if (n == 0)return 1;
	if (n == 1)return x;
	return (double)(((2 * n - 1) * x - fun(n - 1, x) -(n-1)*fun(n - 2, x)) / n);
}
int main(void)
{
	ll n;
	double x;
	scanf("%lld%lf",&n, &x);
	printf("%lf",fun(n, x));
}