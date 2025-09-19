#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

struct pa {
	ll no;
	int color;
};

pa a[100001];
map<int, int> map1;
int sum[100001];
bool sa(pa e,pa f){ return e.no < f.no; }
int main(void) 
{
	int n; char s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].no >> s;
		if (s == 'W')a[i].color = 1;
		else a[i].color = -1;
	}
	sort(a + 1, a + n + 1, sa);
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i].color;
		if (sum[i] < 0 && map1[sum[i]] == 0)map1[sum[i]] = i+1;
		else if (sum[i] < 0)res = max(res, a[i].no - a[map1[sum[i]]].no);
		if (sum[i] >= 0 && sum[i] % 2 == 0)res = max(res, a[i].no - a[1].no);
		else if (sum[i] >= 0)res = max(res, a[i].no - a[2].no);
	}
	cout << res;
	return 0;
}