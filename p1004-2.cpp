//方格取数~深搜  ～(￣▽￣～)(～￣▽￣)～
#include<iostream>
using namespace std;
int N = 0;
int s[11][11], f[11][11][11][11];
int dfs(int x, int y, int x2, int y2)
{
	if (f[x][y][x2][y2] != -1) return f[x][y][x2][y2];
	if (x == N && y == N && x2 == N && y2 == N) return 0;
	int M = 0;

	if (x < N && x2 < N)
		M = max(M, dfs(x + 1, y, x2 + 1, y2) + s[x + 1][y] + s[x2 + 1][y2] - s[x + 1][y] * (x + 1 == x2 + 1 && y == y2));
	if (x < N && y2 < N)
		M = max(M, dfs(x + 1, y, x2, y2 + 1) + s[x + 1][y] + s[x2][y2 + 1] - s[x + 1][y] * (x + 1 == x2 && y == y2 + 1));
	if (y < N && x2 < N)
		M = max(M, dfs(x, y + 1, x2 + 1, y2) + s[x][y + 1] + s[x2 + 1][y2] - s[x][y + 1] * (x == x2 + 1 && y + 1 == y2));
	if (y < N && y2 < N) 
		M = max(M, dfs(x, y + 1, x2, y2 + 1) + s[x][y + 1] + s[x2][y2 + 1] - s[x][y + 1] * (x == x2 && y + 1 == y2 + 1));
	f[x][y][x2][y2] = M;
	return M;
}
int main()
{
	cin >> N;
	//将记录数组初始化成-1，因为可能出现取的数为0的情况，如果直接判断f[x][y][x2][y2]!=0（见dfs第一行）
	//可能出现死循环而导致超时，细节问题 
	for (int a = 0; a <= N; a++)
		for (int b = 0; b <= N; b++)
			for (int c = 0; c <= N; c++)
				for (int d = 0; d <= N; d++) f[a][b][c][d] = -1;
	for (;;)//读入 
	{
		int t1 = 0, t2 = 0, t3 = 0;
		cin >> t1 >> t2 >> t3;
		if (t1 == 0 && t2 == 0 && t3 == 0) break;
		s[t1][t2] = t3;
	}
	cout << dfs(1, 1, 1, 1) + s[1][1];//输出，因为dfs中没有考虑第一格，即s[1][1]，所以最后要加一下 
	return 0;
}