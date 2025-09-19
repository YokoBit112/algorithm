#pragma GCC optimize(2)//手动o2
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long 
ll n, m = 1, ans = 0;//m记录坐标数
ll c[40100] = { 0 };
//因为c要把起点与终点存下来，所以开40100
ll a[20100], b[20100];//a存起点，b存终点
bool flag[40100];//判断是否有效
inline void read(ll& x)//快读
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
inline ll find(ll key)//找原来位置
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
    }//把a,b存入c数组里去
    sort(c + 1, c + m + 1);//排序坐标
    for (ll i = 1; i <= n; ++i)
    {
        a[i] = find(a[i]);
        b[i] = find(b[i]) - 1;//找原位置
        for (ll j = a[i]; j <= b[i]; ++j)
            flag[j] = true;//为有效
    }
    for (ll i = 1; i <= m; ++i){if (flag[i])ans += c[i + 1] - c[i];//有效，加入ans}
    printf("%ld", ans);
}