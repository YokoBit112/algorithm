#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
ll s[1000001] = { 0 };
int main(void)
{
	bool su = false;
	int n, a;
	cin >> a >> n;
	loop:if ((double)sqrt(a) != (int)sqrt(a))
	{
		a++; goto loop;
	}
	for (int i = 0; i != n; i++)
	{
		cin >> s[i];
		if (s[i] < a)
		{
			s[i] = a;
		}
		else if (s[i] % a == 0 || (double)sqrt(s[i]) == (int)sqrt(s[i]))
		{
			s[i] = 0;
		}
		else {
			while (s[i] % a == 0 || (double)sqrt(s[i]) == (int)sqrt(s[i]))s[i]++;
		}
	}
	for (int i = 0; i != n; i++)
	{
		if (s[i])cout << s[i] << endl;
		else cout << "lucky" << endl;
	}
	return 0;
}