#include <iostream>
#include <string>
using namespace std;

string lis(string a) {
	string se;
	bool sea = false;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (!sea && a[i] == '0')continue;
		else {
			sea = true;
		}
		se.push_back(a[i]);
	}
	if (se.empty())return "0";
	else return se;
}
string lis1(string a) {
	string se;
	bool qs = false;
	for (int i = a.size() - 1; i >= 0; i--) {
		se.push_back(a[i]);
	}
	for (int i = se.size() - 1; i >= 0; i--) {
		if (se[i] == '0')continue; else {
			se = se.substr(0, i+1); qs = true;
			break;
		}
	}
	if (qs)return se;
	else return "0";
}
int main(void)
{
	string a1, a2,res; char s;
	cin >> a1;
	bool sf = true;
	for (int i = 0; i < a1.size(); i++)
	{
		if (a1[i] > '9' || a1[i] < '0') {
			a2 = a1.substr(0, i); s = a1[i];
			if (i != a1.size() - 1)a1 = a1.substr(i + 1, a1.size());
			else sf = false;
			break;
		}
	}
	if (a2.empty()) {
		cout<<lis(a1);
	}
	else {
		if (sf) {
			if (s != '/')
				res = lis(a2) + s + lis1(a1);
			else res = lis(a2) + s + lis(a1);
		}
		else {
			res = lis(a2) + s;
		}
		cout << res;
	}
	return 0;
}