#include <bits/stdc++.h>

using namespace std;

struct node
{
	int left, right,fat;
	int h, z;
};
vector<node> a(100001);

void dfs(int nod, int val)
{
	if (nod >= val)
	{
		if (a[nod].left == 0)
		{
			a[nod].left = val;
		}
		else dfs(a[nod].left, val);
	}
	else {
		if (a[nod].right == 0)
		{
			a[nod].right = val;
		}
		else dfs(a[nod].right, val);
	}
	a[val].fat = nod;
}

char c[1000][1000];
int h;
void print(int nod, int sum)//sum表示该节点前的字符数 
{
	if (!nod) return;//边界
	int t = nod, cnt = 0;//拆数，cnt为位数
	char num[10];
	while (t) num[++cnt] = t % 10 + '0', t /= 10;
	reverse(num + 1, num + cnt + 1);
	print(a[nod].right, sum + 3 + cnt);//递归打印右边
	h++;//h为行数
	a[nod].h = h;
	if (sum)//该节点前有字符 
	{
		for (int i = 1; i <= sum - 2; i++) c[h][i] = '.';//把第h行（即当前行）1~sum-2位设置成'.'
		c[h][sum - 1] = '|', c[h][sum] = '-';
	}
	a[nod].z = sum + 1;//该值的第一个字符的列数为sum+1 
	for (int i = 1; i <= cnt; i++) c[h][sum + i] = num[i];//把sum后的cnt位设置成数
	if (a[nod].left || a[nod].right) c[h][sum + cnt + 1] = '-', c[h][sum + cnt + 2] = '|';//如果不是叶子，把后两位设置成"-|" 
	print(a[nod].left, sum + 3 + cnt);//递归打印左边
}

void work(int nod)
{
	if (!nod) return;//边界 
	int uh = a[nod].h;
	if (a[nod].right)//连接右儿子 
	{
		int rh = a[a[nod].right].h, rz = a[a[nod].right].z;
		for (int i = rh; i <= uh; i++) c[i][rz - 2] = '|';//循环修改
	}
	if (a[nod].left)//连接左儿子 
	{
		int lh = a[a[nod].left].h, lz = a[a[nod].left].z;
		for (int i = uh; i <= lh; i++) c[i][lz - 2] = '|';//循环修改
	}
	work(a[nod].left), work(a[nod].right);//递归 
}

int main(void)
{
	int a,head;
	cin >> a;
	head = a;

	while(cin>>a){dfs(head, a);}
	print(head, 0);//从根开始打印，根前有0个字符 
	work(head);//从根开始连接 
	for (int i = 1; i <= h; i++)//输出 
	{
		for (int j = 1; c[i][j]; j++) cout << c[i][j];
		cout << "\n";
	}
	return 0;
}