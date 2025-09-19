#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[100];
int b[100];
void xz(string& s, int i)
{
	int z = 0;
	if (i - 1 >= 0) {
		if (s[i - 1] == '8') {
			s[i - 1] = '4';
			xz(s, i - 1);
		}
	}
	if (i + 1 < s.size())
	{
		if (s[i + 1] == '8') {
			s[i + 1] = '4';

		}
	}
}
int xyz(string& s)
{
	int z = 0;
	for (int i = 0; i != s.size(); i++)
	{
		if (s[i] == '4')xz(s, i);
	}
	for (int i = 0; i != s.size(); i++)
	{
		if (s[i] == '8')z++;
		else if (s[i] == '4')z--;
	}
	return z;
}
bool mp(int a,int b) { return a > b; }
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = xyz(a[i]);
	}
	sort(b, b + n,mp);
	int i = 1;
	int z = 1;
	while (b[i] == b[i - 1]&&i<n) {
		i++; z++;
	}
	cout << z << " ";
	i = n - 2;
	int e = 1;
	while (b[i] == b[i+1]&&i>0)
	{
		i--; e++;
	}
	if (z != n)cout << e;
	return 0;
}