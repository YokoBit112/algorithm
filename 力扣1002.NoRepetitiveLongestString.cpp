#include <iostream>
#include <string>

using namespace std;
int main(void) {
	string s; string a; int c = 0, d = 0, e;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int b = a.find(s[i]);
		if (b == -1)
			a.push_back(s[i]);
		else {
			if (b >= c) {
				cout << i << " " << c << " " << i - c << endl;
				if (d < i - c)
					d = i - c;
				c = b + 1;
				a.clear();
				i = b - 1;
				//cout << d << endl;
			}
		}
	}
	if (a.size() > d)
	{
		d = a.size(); cout << d << endl;
		//cout << d << endl;
	}
	return d;
}
