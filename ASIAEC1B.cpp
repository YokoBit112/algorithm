#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s1, s2,T;
int q;

vector<int> buildNext(string p) {
	int m = p.size();
	vector<int> nxt(m, 0);
	for (int i = 0,j = 0; i < m; i++) {
		while (j > 0 && p[i] != p[j])j = nxt[j - 1];
		if (p[i] == p[j])j++;
		nxt[i] = j;
	}
	return nxt;
}

int kmp(string s, string p) {
	vector<int> nxt = buildNext(p);
	int n = s.size(), m = p.size();
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])j = nxt[j - 1];
		if (s[i] == p[j]) j++;
		if (j == m) return i - m + 1;
	}
}
ll sum = 0;
void solve(int i, int x) {
	if (x == T.size()) {
		return;
	}
	if (s1[i] == T[i]) {
		solve(i + 1);
	}
	else if (s2[i] == T[i]) {

	}
}


int main(void) {
	cin >> s1 >> s2;
	cin >> q;
	while (q--) {
		cin >> T;
		solve(0);
	}
}