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
void print(int nod, int sum)//sum��ʾ�ýڵ�ǰ���ַ��� 
{
	if (!nod) return;//�߽�
	int t = nod, cnt = 0;//������cntΪλ��
	char num[10];
	while (t) num[++cnt] = t % 10 + '0', t /= 10;
	reverse(num + 1, num + cnt + 1);
	print(a[nod].right, sum + 3 + cnt);//�ݹ��ӡ�ұ�
	h++;//hΪ����
	a[nod].h = h;
	if (sum)//�ýڵ�ǰ���ַ� 
	{
		for (int i = 1; i <= sum - 2; i++) c[h][i] = '.';//�ѵ�h�У�����ǰ�У�1~sum-2λ���ó�'.'
		c[h][sum - 1] = '|', c[h][sum] = '-';
	}
	a[nod].z = sum + 1;//��ֵ�ĵ�һ���ַ�������Ϊsum+1 
	for (int i = 1; i <= cnt; i++) c[h][sum + i] = num[i];//��sum���cntλ���ó���
	if (a[nod].left || a[nod].right) c[h][sum + cnt + 1] = '-', c[h][sum + cnt + 2] = '|';//�������Ҷ�ӣ��Ѻ���λ���ó�"-|" 
	print(a[nod].left, sum + 3 + cnt);//�ݹ��ӡ���
}

void work(int nod)
{
	if (!nod) return;//�߽� 
	int uh = a[nod].h;
	if (a[nod].right)//�����Ҷ��� 
	{
		int rh = a[a[nod].right].h, rz = a[a[nod].right].z;
		for (int i = rh; i <= uh; i++) c[i][rz - 2] = '|';//ѭ���޸�
	}
	if (a[nod].left)//��������� 
	{
		int lh = a[a[nod].left].h, lz = a[a[nod].left].z;
		for (int i = uh; i <= lh; i++) c[i][lz - 2] = '|';//ѭ���޸�
	}
	work(a[nod].left), work(a[nod].right);//�ݹ� 
}

int main(void)
{
	int a,head;
	cin >> a;
	head = a;

	while(cin>>a){dfs(head, a);}
	print(head, 0);//�Ӹ���ʼ��ӡ����ǰ��0���ַ� 
	work(head);//�Ӹ���ʼ���� 
	for (int i = 1; i <= h; i++)//��� 
	{
		for (int j = 1; c[i][j]; j++) cout << c[i][j];
		cout << "\n";
	}
	return 0;
}