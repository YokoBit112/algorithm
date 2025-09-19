#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define ll long long

struct pa
{
	ll no;
	int color;
};

pa a[100001];
ll se[100001], res;
map<ll,int> mas;
bool som(pa s, pa e) { return s.no < e.no; }

int main(void)
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char s;
		cin >> a[i].no>>s;
		if (s == 'W')a[i].color = 1;
		else a[i].color = -1;
	}
	sort(a+1, a + n+1, som);
	mas[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		se[i] = se[i - 1] + a[i].color;
		if (mas[se[i]] == 0 && se[i] < 0) {
			mas[se[i]] = i;
		}
		else if(se[i]<0){
			res = max(res, a[i].no - a[mas[se[i]]+1].no);
		}
		if (se[i] % 2 == 0 && se[i] >= 0)res = max(a[i].no - a[1].no, res);
		else if (se[i] >= 0)res = max(a[i].no - a[2].no, res);
	}
	cout << res;
	return 0;
}