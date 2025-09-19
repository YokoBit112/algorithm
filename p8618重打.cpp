#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*笔记

线段树的运算知：线段树的第一项为[1,n]的最大值，第n项为[n,n]的最大值,对线段树进行无限二分可知，
分割到最后的项必然为[k,k]的最大值

使用位运算构建线段树，观察到

	p<<1	p<<1|1
1	2		3
2	4		5
。。。。。。
这样就可以构造出长度为n的线段树
val[p] = max(val[p << 1], val[p << 1 | 1]);更新val的值，目的是维护父节点的最大值

假设原始数组 num = [3, 1, 4, 2]，构建线段树后：
val[4] = 3（叶子节点，对应区间 [1,1]）
val[5] = 1（叶子节点，对应区间 [2,2]）
val[2] = max(3, 1) = 3（非叶子节点，对应区间 [1,2]）
val[6] = 4（叶子节点，对应区间 [3,3]）
val[7] = 2（叶子节点，对应区间 [4,4]）
val[3] = max(4, 2) = 4（非叶子节点，对应区间 [3,4]）
val[1] = max(3, 4) = 4（根节点，对应区间 [1,4]）

对于每次在编号内的查询知：只有mid>=L或mid<R才有递归意义，最后递归到的所有数据在[L,R]区间


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