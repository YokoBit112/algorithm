#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
char a[2002], b[2002];
int m = 0,n = 0,c[4002] = {0}, w;
int main(void)
{
	cin >> a >> b;for (; n != 2002; n++){if (a[n] == '\0')break;}for (; m != 2002; m++){if (b[m] == '\0')break;}
	for (int i = n-1; i >= 0; i--)
	{
		w = n - i-1;
		for (int p = m-1; p >= 0; p--)
		{
			c[w++] += (a[i] - '0') * (b[p] - '0');
		}
	}
	int jw = 0;
	for (int i = 0; i < w; i++)
	{
		c[i] += jw;
		if (c[i] > 9) {
			jw = c[i] / 10;
			c[i] = c[i] % 10;
		}
		else jw = 0;
	}
	if (jw > 0)c[w++] = jw;
	while (c[w] == 0) {
		w--; if (w == 0)break;
	}
		for (int i = w; i >= 0; i--)
		{
			cout << c[i];
		}
	return 0;
}