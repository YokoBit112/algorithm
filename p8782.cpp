#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, ma, mb;
ll numa[100001], numb[100001];
const ll mod = 1000000007;
int main(void)
{
	cin >> n;
	cin >> ma;
	for (int i = 0;i < ma; i++)
	{
		cin >> numa[i];
	}
	cin >> mb;
	for (int i = 0; i < mb; i++)
	{
		cin >> numb[i];
	}
	ll ans = 0, res = 1;
	reverse(numa, numa + ma);
	reverse(numb, numb + mb);
	int i = 0;
	for (int i = max(ma, mb) - 1; i >= 0; i--)//ȡ�ϴ�λ��
	{
		ans = (ans * max((ll)2, max(numa[i] + 1, numb[i] + 1)) + numa[i] - numb[i] + mod) % mod;//�ؾ����㷨��ע�������
	}
	cout << ans << endl;
}