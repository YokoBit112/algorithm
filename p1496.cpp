#pragma GCC optimize(2)//�ֶ�o2
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long 
ll n, m = 1, ans = 0;//m��¼������
ll c[40100] = { 0 };
//��ΪcҪ��������յ�����������Կ�40100
ll a[20100], b[20100];//a����㣬b���յ�
bool flag[40100];//�ж��Ƿ���Ч
inline void read(ll& x)//���
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}
inline ll find(ll key)//��ԭ��λ��
{
    for (int i = 1; i <= m; ++i)
    {
        if (c[i] == key)
            return i;
    }
}
int main()
{
    read(n);
    for (ll i = 1; i <= n; ++i)
    {
        read(a[i]);read(b[i]);
        c[m] = a[i];m++;
        c[m] = b[i];m++;
    }//��a,b����c������ȥ
    sort(c + 1, c + m + 1);//��������
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = find(a[i]);
        b[i] = find(b[i]) - 1;//��ԭλ��
        for (ll j = a[i]; j <= b[i]; ++j)
            flag[j] = true;//Ϊ��Ч
    }
    for (ll i = 1; i <= m; ++i){if (flag[i])ans += c[i + 1] - c[i];//��Ч������ans}
    printf("%ld", ans);
}