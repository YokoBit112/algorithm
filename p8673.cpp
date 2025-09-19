//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define ll long long
//
//int n, dex[] = { 1,-1,0,0 }, dey[] = { 0,0,1,-1 }, k;
//char mapp[1010][1010];
//bool bj[1010][1010][15];
//ll minstep = 1e12;
//
//void bfs(int x,int y,int wd,int step)
//{
//	bj[x][y][wd] = 1;
//	if (x == 0 || y == 0 || x > n || y > n)return;
//	if (x == n && y == n) {
//		if (minstep > step)minstep = step;
//	}
//	if (mapp[x][y] == '%') {
//
//		
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (mapp[x - dex[i]][y - dey[i]] == '%' && !bj[x - dex[i]][y - dey[i]][wd])
//		{
//			mapp[x - dex[i]][y - dey[i]] = '.';
//			bfs(x - dex[i], y - dey[i], k , step + 1);
//			
//		}
//		if (wd && !bj[x - dex[i]][y - dey[i]][wd-1] && mapp[x - dex[i]][y - dey[i]] == 'X')
//		{
//			bfs(x - dex[i], y - dey[i], wd-1, step + 1);
//		}
//		if (wd&&mapp[x - dex[i]][y - dey[i]] == '.' && !bj[x - dex[i]][y - dey[i]][wd-1])
//		{
//			bfs(x - dex[i], y - dey[i], wd-1, step + 1);
//		}
//		if (!wd && mapp[x - dex[i]][y - dey[i]] == '.' && !bj[x - dex[i]][y - dey[i]][wd])
//		{
//			bfs(x - dex[i], y - dey[i], wd, step + 1);
//		}
//
//	}
//}
//
//int main(void)
//{
//	cin >> n >> k;
//	memset(bj, 0, sizeof(bj));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int p = 1; p <= n; p++)
//		{
//			cin >> mapp[i][p];
//		}
//	}
//	bfs(1, 1, 0, 0);
//	if (minstep != 1e10)cout << minstep;
//	else cout << -1;
//}


#include <bits/stdc++.h>

using namespace std;

struct node {
	int cx,cy,sum,time;
};
int n, k;
char mapp[1005][1005];
int dex[4] = { -1,1,0,0 };
int dey[4] = { 0,0,-1,1 };
bool bj[1005][1005][15];

int bfs(int x, int y) {
	queue<node> q;
	node v;
	v.cx = x;
	v.cy = y;
	v.sum = 0;
	v.time = 0;
	q.push(v);
	bj[x][y][v.time] = true;//第一个位置。
	while (!q.empty()) {
		node f = q.front();  //当前位置。
		q.pop();
		if (f.cx == n && f.cy == n) {  //走出迷宫。
			return f.sum;
		}
		for (int i = 0; i < 4; i++) {  //四个方向。
			node tmp;
			tmp.cx = f.cx + dex[i];
			tmp.cy = f.cy + dey[i];
			if (mapp[tmp.cx][tmp.cy] != '#' && tmp.cx >= 1 && tmp.cy >= 1 && tmp.cx <= n && tmp.cy <= n) {
				if (mapp[tmp.cx][tmp.cy] == '%' && !bj[tmp.cx][tmp.cy][f.time]) {
					bj[tmp.cx][tmp.cy][k] = true;
					mapp[tmp.cx][tmp.cy] = '.';
					tmp.time = k;
					tmp.sum = f.sum + 1;
					q.push(tmp);
				}
				if (f.time && !bj[tmp.cx][tmp.cy][f.time - 1] && mapp[tmp.cx][tmp.cy] == 'X') {
					bj[tmp.cx][tmp.cy][f.time - 1] = true;
					tmp.sum = f.sum + 1;
					tmp.time = f.time - 1;
					//走一步就会减少一个无敌时间，下同。
					q.push(tmp);
				}
				if (f.time && !bj[tmp.cx][tmp.cy][f.time - 1] && mapp[tmp.cx][tmp.cy] == '.') {
					bj[tmp.cx][tmp.cy][f.time - 1] = true;
					tmp.sum = f.sum + 1;
					tmp.time = f.time - 1;
					q.push(tmp);
				}
				if (f.time == 0 && !bj[tmp.cx][tmp.cy][0] && mapp[tmp.cx][tmp.cy] == '.') {
					//当无剩余无敌时间且可以经过时。
					bj[tmp.cx][tmp.cy][0] = true;
					tmp.sum = f.sum + 1;
					tmp.time = 0;
					//无敌时间依然是0。
					q.push(tmp);
				}
			}
		}
	}
	return -1;   //不能通过迷宫。
}
int main() {
	cin >> n >> k;
	//k为无敌时间。
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapp[i][j]; //输入。
		}
	}
	cout << bfs(1, 1) << endl; //输出最短路。
	return 0;
}