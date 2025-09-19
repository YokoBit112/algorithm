#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*�ʼ�

�߶���������֪���߶����ĵ�һ��Ϊ[1,n]�����ֵ����n��Ϊ[n,n]�����ֵ,���߶����������޶��ֿ�֪��
�ָ�������ȻΪ[k,k]�����ֵ

ʹ��λ���㹹���߶������۲쵽

	p<<1	p<<1|1
1	2		3
2	4		5
������������
�����Ϳ��Թ��������Ϊn���߶���
val[p] = max(val[p << 1], val[p << 1 | 1]);����val��ֵ��Ŀ����ά�����ڵ�����ֵ

����ԭʼ���� num = [3, 1, 4, 2]�������߶�����
val[4] = 3��Ҷ�ӽڵ㣬��Ӧ���� [1,1]��
val[5] = 1��Ҷ�ӽڵ㣬��Ӧ���� [2,2]��
val[2] = max(3, 1) = 3����Ҷ�ӽڵ㣬��Ӧ���� [1,2]��
val[6] = 4��Ҷ�ӽڵ㣬��Ӧ���� [3,3]��
val[7] = 2��Ҷ�ӽڵ㣬��Ӧ���� [4,4]��
val[3] = max(4, 2) = 4����Ҷ�ӽڵ㣬��Ӧ���� [3,4]��
val[1] = max(3, 4) = 4�����ڵ㣬��Ӧ���� [1,4]��

����ÿ���ڱ���ڵĲ�ѯ֪��ֻ��mid>=L��mid<R���еݹ����壬���ݹ鵽������������[L,R]����


*/

int n, m,s;
ll sum;
int L, R;
map<int, ll> num,val;

void build(int p,int l, int r)
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


void finde(int p, int l, int r)
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
	if(L<=mid)finde(p << 1, l, mid);
	if(mid<R)finde(p << 1 | 1, mid + 1, r);
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

	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		cin >> L >> R;
		finde(1, 1, n);
		cout << sum << endl;
	}

}