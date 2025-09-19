#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main(void)
{
	int n;
	string a;
	cin >> n >> a;
    int res = 0;
	for (int i = 0; i < n; i++)
	{
        int re = 0;
        int se = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] == '0') {
                re++;
            }
            else {
                se++;
            }
            if (re == se) {
                res++;
            }
        }
	}
    cout << res;
    return 0;
}