#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int mape[12][12], map1[11][11][11][11];

int n;

int dfs(int a, int b, int c, int d) {
	if (map1[a][b][c][d] != -1)return map1[a][b][c][d];
	if (a == n && b == n && c == n && d == n)return 0;
	int max1 = 0;
	if (a < n && c < n) {// same down
		max1 = max(max1, dfs(a + 1, b, c + 1, d) + mape[a + 1][b] + mape[c + 1][d] - mape[a + 1][b] * (a == c && b == d));
	}
	if (a < n && d < n) {//first down second right
		max1 = max(max1, dfs(a + 1, b, c, d + 1) + mape[a + 1][b] + mape[c][d + 1] - mape[a + 1][b] * (a + 1 == c && d + 1 == b));
	}
	if (b < n && c < n) {//first right second down
		max1 = max(max1, dfs(a, b + 1, c + 1, d) + mape[a][b + 1] + mape[c + 1][d] - mape[a][b + 1] * (a == c + 1 && b + 1 == d));
	}
	if (b < n && d < n)//same right
	{
		max1 = max(max1, dfs(a, b + 1, c, d + 1) + mape[a][b + 1] + mape[c][d + 1] - mape[a][b + 1] * (a == c && b == d));
	}
	map1[a][b][c][d] = max1;
	return max1;
}

int main(void)
{
	int e = -1,f = -1,g = -1;
	cin >> n;
	while (!(e == 0 && f == 0 && g == 0))
	{
		cin >> e >> f >> g;
		if (e == 0 && f == 0 && g == 0)break;
		mape[e][f] = g;
	}
	memset(map1, -1, sizeof(map1));
	cout << dfs(1, 1, 1, 1)+mape[1][1];
	return 0;
}