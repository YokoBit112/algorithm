#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
	string a, b,c,g;
	cin >> a >> b;
	int p = max(a.size(), b.size());
	bool as = true, bs = true;
	auto e = a.end()-1;
	auto f = b.end()-1;
	int d = 0;
	for (int i = 0; i < p; i++)
	{
		if (as && bs) {
			char tem = *e + *f - '0' + d; if (e != a.begin())e--; else as = false; if (f != b.begin()) f--; else bs = false;
			if (tem - '0' > 9) { tem -= 10; d = 1; }
			else d = 0;
			g.push_back(tem);
		}
		else if(!as)
		{
			if (d == 0)
				g.push_back(*f);
			else {
				if (*f + 1 - '0' > 9) {
					g.push_back(*f - 9); d = 1;
				}
				else {
					g.push_back(*f + 1); d = 0;
				}
			}
			if(f!=b.begin())
			f--;
		}
		else if (!bs) {
			if (d == 0)
				g.push_back(*e);
			else {
				if (*e + 1 - '0' > 9) {
					g.push_back(*e - 9); d = 1;
				}
				else {
					g.push_back(*e + 1); d = 0;
				}
			} if(e!=a.begin())e--;
		}
	}
	if (d == 1)g.push_back('1');
	for (int i = g.size()-1; i>=0; i--)
	{
		cout << g[i];
	}
	return 0;
}