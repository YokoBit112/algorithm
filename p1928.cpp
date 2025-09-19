#include <iostream>
#include <string>

using namespace std;
void jb(string a) {

}
void res(string a) {
	bool s = true;
	for (int i = 0; i < a.size(); i++) {
		if (s && a[i] != '[')cout << a[i];
		else {
			while (a[++i] != ']');

		}
	}
}

int main(void)
{
	string a;
	cin >> a;
	res(a);
}