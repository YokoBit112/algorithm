#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define YES "YES"
#define NO "NO"
ll t, n, a[200010], b[200010];
//纯唐
//bool dfs(int k) {
//	if (a[k] == b[k]) {
//		if (k + 1 < n)return dfs(k + 1);
//		else return 1;
//	}
//	else if (k + 1 >= n)return 0;
//	else {
//		if ((a[k] ^ a[k + 1]) == b[k]) {
//			a[k] = b[k];
//			return dfs(k + 1);
//		}//满足条件继续运行
//		else if ((a[k] ^ b[k + 1]) == b[k])
//		{
//			if (dfs(k + 1)) {
//				if ((a[k] ^ a[k + 1]) == b[k])return 1;
//				else return 0;
//			}
//			else return 0;
//		}
//		else return 0;
//	}
//}

bool solve() {
	if (a[n - 1] != b[n - 1])return 0;
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] != b[i] && (a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i]) {
			return 0;
		}
	}
	return 1;

}


int main(void)
{
	cin >> t;
	while (t--) {
		cin >> n;
		bool bt = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		if (solve())cout << YES << endl;
		else cout << NO << endl;
	}
	return 0;
}