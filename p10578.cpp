#include <bits/stdc++.h>
#include <unordered_map> 

using namespace std;
unordered_map<string, int> hashh;
int t;
string mapp, t1 = "123456789";
char le;

void bfs()
{
	queue<string> q;
	q.push(t1);
	hashh[t1] = 1;
	while (q.size())
	{
		string now = q.front();
		q.pop();
		string tem[4] = { now,now,now,now };
		tem[0][0] = now[1], tem[0][1] = now[4], tem[0][3] = now[0], tem[0][4] = now[3];
		tem[1][1] = now[2], tem[1][2] = now[5], tem[1][4] = now[1], tem[1][5] = now[4];
		tem[2][3] = now[4], tem[2][4] = now[7], tem[2][6] = now[3], tem[2][7] = now[6];
		tem[3][4] = now[5], tem[3][5] = now[8], tem[3][7] = now[4], tem[3][8] = now[7];
		for (int i = 0; i < 4; i++)
		{
			if (!hashh[tem[i]] && tem[i] != t1)
			{
				hashh[tem[i]] = hashh[now] + 1;
				if (now[i] == t)continue;
				q.push(tem[i]);
			}
		}

	}

}

int main(void)
{
	cin >> t;
	bfs();
	for (int i = 0; i < t; i++)
	{
		mapp.clear();
		for (int p = 0; p < 9; p++)
		{
			cin >> le;
			mapp.push_back(le);

		}
		cout << hashh[mapp]-1 << endl;
	}
}