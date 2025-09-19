#include <iostream>

using namespace std;



int main(void)
{
	long long a, b, c, temp;
	cin >> a >> b >> c;
	if (a < b) { temp = b; b = a; a = temp; }
	if (c > a) { temp = a; a = c; c = temp; }
	if (b + c <= a) {
		cout << "Not triangle"; return 0;
	}
	b *= b; c *= c; a *= a;
	if (b + c == a) { cout << "Right triangle" << endl; }
	else if (b + c > a) { cout << "Acute triangle" << endl; }
	else { cout << "Obtuse triangle" << endl; }
	if (a == b || b == c || a == c)
	{
		cout << "Isosceles triangle" << endl;
		if (a == b && b == c)
		{
			cout << "Equilateral triangle" << endl;
		}
	}
	return 0;
}