#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll l, r;
ll ksm[100000];

void build(int s, int t, int p) {
	// 对 [s,t] 区间建立线段树,当前根的编号为 p
	if (s == t) {
		d[p] = a[s];
		return;
	}
	int m = s + ((t - s) >> 1);
	// 移位运算符的优先级小于加减法，所以加上括号
	// 如果写成 (s + t) >> 1 可能会超出 int 范围
	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	// 递归对左右区间建树
	d[p] = d[p * 2] + d[(p * 2) + 1];
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> l >> r;
	ksm[0] = 1;
	for (int i = 1;i < 100;i++) {
		ksm[i] = ksm[i - 1] * 2;
		cout << ksm[i] << endl;
	}

}