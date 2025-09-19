#include <iostream>

using namespace std;
char a[1001][1001]; bool as[1001][1001];
int b[4][2] = { {0,1},{1,0},{-1,0}, { 0,-1 } };//down right left up

int BFS(int x,int y,int s) {
	if (!as[y][x])as[y][x] = 1;
	else return -1;
	if (a[y][x] == '.')s++;
	for (int i = 0; i < 4; i++)
	{
		BFS(x + b[i][0], y + b[i][0], s);
	}
	return s;
}

int main(void)
{
	int n, m,x = 0,y = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < m; p++)
		{
			cin >> a[i][p];
			if (a[i][p] == '@'){y = i; x = p;}
		}
	}
	cout << BFS(x,y,0);
}