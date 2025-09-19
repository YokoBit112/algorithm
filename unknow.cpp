#include<iostream>
#include <vector>
using namespace std;
int main(void)
{
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	c++;
	vector<int> d = { 1,0,1,0,1,0,1,1,0,1,0,1 };
	if (b != 2)
	{
		if (c > 30 + d[b])
		{
			c = 1;
			b += 1;
			if (b > 12)
			{
				b = 1;
				a++;
			}
		}
	}
	else {
		if (a % 4 == 0)
		{
			if (c > 29)
			{
				c = 1;
				b += 1;
			}
		}
		else {
			if (c > 28)
			{
				c = 1;
				b += 1;
			}
		}
		cout << a << "-";
		if (b < 10)cout << "0" << b << "-";
		else cout << b << "-";
		if (c < 10)cout << "0" << c;
		else cout << c;
	}
}