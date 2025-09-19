#include <iostream>

using namespace std;

int mon[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
	int n;
	cin >> n;
	int y = 2024, m = 6, d = 11;
	d -= n;
	while (d<= 0)
	{
		if (m == 1)m = 13;
		d += mon[m - 1];
		m--;
		if (m == 12) {
			y--;
			if (y % 4 == 0)
			{
				if (y % 100 == 0)
				{
					if (y % 400 == 0)mon[2] = 29;
					else mon[2] = 28;
				}
				else mon[2] = 29;
			}
			else mon[2] = 28;
		}
	}
	if (m == 13)m = 1;
	cout << y << "-" << m << "-" << d;
	return 0;

}