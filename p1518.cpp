#include <iostream>

using namespace std;

char a[12][12];
int nx, ny, jx, jy,nf= 0,jf = 0,min1 = 0;
bool only[16001000];
void move(int x, int y, int mi, int h) {//ÒÆ¶¯º¯Êý
	if (mi == 0) {
		if (a[x - 1][y] == '*') if (h == 0) jf = 1; else nf = 1;
		else if (h == 0) jx--; else nx--;
	}
	else if (mi == 1) {
		if (a[x][y + 1] == '*') if (h == 0) jf = 2; else nf = 2;
		else if (h == 0) jy++; else ny++;
	}
	else if (mi == 2) {
		if (a[x + 1][y] == '*') if (h == 0) jf = 3; else nf = 3;
		else if (h == 0) jx++; else nx++;
	}
	else {
		if (a[x][y - 1] == '*') if (h == 0) jf = 0; else nf = 0;
		else if (h == 0) jy--; else ny--;
	}
}

int main(void)
{
	for (int i = 0; i != 12; i++)
	{
		for (int p = 0; p != 12; p++)
		{
			if (i == 0 || i == 11 || p == 0 || p == 11) {
				a[i][p] = '*'; continue;
			}
			cin >> a[i][p];
			if (a[i][p] == 'C') { nx = i; ny = p; a[i][p] = '.'; }
			if (a[i][p] == 'F') { jx = i; jy = p; a[i][p] = '.'; }
		}
	}
	while (!((nx == jx && ny == jy)))
	{
		int tdz = jx+jy* 10 + nx * 100 + ny * 1000 + jf * 10000 + nf * 40000;
		
		if (only[tdz]) {
			cout << 0 << endl;
			return 0;
		}only[tdz] = 1;
		min1++;
		move(jx, jy, jf, 0); move(nx, ny, nf, 1);
		/*if (nf == 0)
		{
			if (a[nx-1][ny]!='*')nx--;
			else nf = 1;
		}
		if (nf == 1)
		{
			if (a[nx][ny+1]!='*')ny++;
			else nf = 2;
		}
		if (nf == 2)
		{
			if (a[nx+1][ny]!='*')nx++;
			else nf = 3;
		}
		if (nf == 3)
		{
			if (a[nx][ny-1]!='*')ny--;
			else nf = 0;
		}
		if (jf == 0)
		{
			if (a[jx-1][jy] != '*')jx--;
			else jf = 1;
		}
		if (jf == 1)
		{
			if (a[jx][jy+1] != '*')jy++;
			else jf = 2;
		}
		if (jf == 2)
		{
			if (a[jx+1][jy] != '*')jx++;
			else jf = 3;
		}
		if (jf == 3)
		{
			if (a[jx][jy-1] != '*')jy--;
			else jf = 0;
		}*/
	}
	cout << min1++<<endl;
	return 0;
}