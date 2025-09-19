#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>

#define ll long long
using namespace std;
int s[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct Date {
	int year;
	int month;
	int day;
};
bool FishNet(Date a)
{
	int y = 1900, m = 1, d = 1,sum = 1;
	while (!(y == a.year && m == a.month && d == a.day))
	{
		d++; sum++;
		if (d > s[m - 1]) {
			d -= s[m - 1]; m++;
			if (m > 12) {
				m -= 12; y++;
				if (y % 4 == 0)
				{
					if (y % 100 == 0)
					{
						if (y % 400 == 0)s[1] = 29;
						else s[1] = 28;
					}
					else {
						s[1] = 29;
					}
				}
				else s[1] = 28;
			}
		}
	}
	if (sum % 5 == 4 || sum % 5 == 0)return 0;
	else return 1;
}
int main(void)
{
	Date star;
	scanf("%d%d%d", &star.year, &star.month, &star.day);
	if (FishNet(star))printf("¥Ú”„");
	else printf("…πÕ¯");
	loop:return 0;
}