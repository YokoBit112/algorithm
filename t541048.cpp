#include <iostream>
#include <string>

using namespace std;
string a;
int l[100001], r[100001];
int main(void)
{
	int n;
	cin >> n;
	char s;
	cin >> a;
	for (int i = 0; i != n; i++)
	{
		cin >> s;
		if (s == 'R')r[i]++;
		else l[i]++;
	}
	for (int i = 1; i != n; i++)
	{
		r[i] += r[i - 1];
	}
	for (int i = n- 2; i >= 0; i--)
	{
		l[i] += l[i + 1];
	}
	for (int i = 0; i != n; i++)
	{
		if (a[i] == 'L')
			cout << l[i] << " ";
		else cout << r[i] << " ";

	}
	return 0;
}