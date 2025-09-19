#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const int& s1, const int& s2) {
	return s1 > s2;
}
int main()
{
	int max1(int a, int b, int c);
	int max2(int a, int b, int c,int d);
	int max3(int a, int b, int c);
	int a, b, c, g[3] = {0,0,0},x;
	while (1) {
		scanf_s("%d%d%d%d", &a, &b, &c, &x);
		g[0] = a; g[1] = b; g[2] = c;
		int d = max1(a, b, c);
		int e = max2(a, b, c, x);
		int f = max3(a, b, c);
		sort(g, g + 3, cmp);
		printf("%d\n%d\n%d\n%d\n", d, e, f, g[0]);
	}
	return 0;
}
int max1(int a, int b, int c)
{
	int e = (a > b) ? a : b;
	int f = (e > c) ? e : c;
	return f;
}
int max2(int a, int b, int c,int d)
{
	if (a > b && a > c && a > d)return a;
	if (b > a && b > c && b > d)return b;
	if (c > a && c > b && c > d)return c;
	if (d > a && d > b && d > c)return d;
}
int max3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)return a;
	}
	else {
		if (b > c)return b;
		else return c;
	}
}