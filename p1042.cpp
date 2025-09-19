#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;
int a[6000][2], b[6000][2], l11 = 0, w11 = 0, w21, l21,wa11,wa21;
int main(void)
{
	int tem = 0;
	char la = '0';
	while (la != 'E')
	{
		tem++;
		scanf("%c", &la);
		if (la == 'W')
		{
			w11++; w21++;
		}
		else if(la == 'L'){
			l11++; l21++;
		}
		if (l11 >= 11 || w11 >= 11)
		{
			if (abs(l11 - w11) >= 2)
			{
				a[wa11][0] = w11; a[wa11][1] = l11;
				w11 = 0; l11 = 0; wa11++;
			}
		}
		if (w21 >= 21 || l21 >= 21)
		{
			if (abs(l21 - w21) >= 2)
			{
			b[wa21][0] = w21; b[wa21][1] = l21;
			w21 = 0; l21 = 0; wa21++;
			}
		}
	}
	a[wa11][0] = w11; a[wa11][1] = l11; b[wa21][0] = w21; b[wa21][1] = l21;
	wa11++; wa21++;
	for (int i = 0; i != wa11; i++)
	{
		cout << a[i][0] << ":" << a[i][1] << endl;
	}
	cout << endl;
	for (int i = 0; i != wa21; i++)
	{
		cout << b[i][0] << ":" << b[i][1] << endl;
	}

}