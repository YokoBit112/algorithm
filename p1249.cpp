#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000];
string i2s(int s) {
	if (s == 0)return "0";
	string sa, se;
	while (s != 0) {
		se.push_back(s % 10 + '0');
		s /= 10;
	}
	for (int i = se.size() - 1; i >= 0; i--) {
		sa.push_back(se[i]);
	}
	return sa;
}

string add(string a, string b) {
	int s[500] = { 0 }, e[500] = { 0 }, cj[500]{};
	for (int i = a.size() - 1; i >= 0; i--) {
		s[a.size() - 1 - i] = a[i] - '0';
	}
	for (int i = b.size() - 1; i >= 0; i--) {
		e[b.size() - 1 - i] = b[i] - '0';
	}
	for (int i = 0; i != a.size(); i++) {
		for (int p = 0; p != b.size(); p++) { cj[p + i] += (s[i] * e[p]); }
	}//cout << s[i] << " " << e[p] << " " << s[i] * e[p] << endl; } }
	int jw = 0; string res;
	for (int p = 0; p != b.size() + a.size(); p++) {
		cj[p] += jw;
		jw = cj[p] / 10;
		cj[p] %= 10;
		//cout << cj[p] << endl;
	}bool qdl = true;
	for (int p = b.size() + a.size(); p >= 0; p--) {
		
		if (qdl && cj[p] == 0)continue;
		else qdl = false;
		res.push_back(cj[p]+'0');
	}
	return res;
}

int main(void) {
	cin >> n;
	if (n < 5) {
		cout << n << endl << n;
	}
	else {
		int i = 2;
		while (n - i >= 0) {
			a[i - 2] = i;
			n -= i++;
		}
		i -= 2;
		if (n > i) {
			int p = n / i;
			n = n % i;
			for (int q = 0; q != i; q++) {
				a[q] += p;
			}
			for (int q = i - n; q != i; q++) {
				a[q] += 1;
			}
		}
		else {
			for (int p = i - n; p != i; p++) {
				a[p]++;
			}
		}
		string result = i2s(a[0]);
		cout << a[0] << " ";
		for (int p = 1; p < i; p++) {
			result = add(result, i2s(a[p]));
			cout << a[p];
			if (p != i - 1)cout << " ";
		}
		cout << endl<< result;
	}
	return 0;
}