#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll l, r;
ll ksm[100000];

void build(int s, int t, int p) {
	// �� [s,t] ���佨���߶���,��ǰ���ı��Ϊ p
	if (s == t) {
		d[p] = a[s];
		return;
	}
	int m = s + ((t - s) >> 1);
	// ��λ����������ȼ�С�ڼӼ��������Լ�������
	// ���д�� (s + t) >> 1 ���ܻᳬ�� int ��Χ
	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	// �ݹ���������佨��
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