#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<int, ll> num,val;

int n, m;
ll sum = 0;
//¹¹½¨Ïß¶ÎÊ÷
void build(int p,int l,int r)
{
	if (l == r)
	{
		val[p] = num[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	val[p] = max(val[p << 1], val[p << 1 | 1]);
}

void finde(int p,int l, int r,int L,int R)
{
	static int tem;
	if (val[p] <= 2)return;
	if (l == r)
	{
		tem = (int)log2(val[p]) + 1;
		sum -= (val[p] - tem);
		val[p] = tem;
		return;
	}
	int mid = (l + r) >> 1;
	if(L<=mid)finde(p << 1, l, mid,L,R);
	if(R>mid)finde(p << 1 | 1,mid + 1, r,L,R);
	val[p] = max(val[p << 1], val[p << 1 | 1]);
}

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		sum += num[i];
	}
	build(1,1,n);
	int l, r;
	while (m--)
	{
		cin >> l >> r;
		finde(1, 1, n, l, r);
		cout << sum << endl;
	}
	return 0;
}