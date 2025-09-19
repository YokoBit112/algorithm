#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int max_dis = 2000,max_tab1 = 200000;

int dis[max_tab1];
bool bj[2][max_dis*max_dis];
int ans[2];

int nxt(int p,int o)
{
	int x = p / max_dis, y = p % max_dis;
	if (o & 1)y = y / 3 * 3 + 3 - y % 3;
	if (o & 2)x = x / 3 * 3 + 3 - x % 3;
	return x * max_dis + y;
}

int main(void)
{
	for (int i = 2, num = 0; i < max_dis, num < max_tab1;i++)
	{
		if(i%3 == 2)
		{
			for (int x = 1;x<i,num<max_tab1;x+=3)
			{
				dis[num++] = x * max_dis + i - x;
			}
		}
		else if(!(i%3))
		{
			for (int x = 1; x < i-1, num < max_tab1;x++)
			{
				if(x%3 == 1)
				{
					dis[num++] = x * max_dis + i - x;
				}
				else if(x%3 == 2)
				{
					dis[num++] = x * max_dis + i - x - 2;
					dis[num++] = x * max_dis + i - x;
				}
			}
			dis[num++] = (i - 1) * max_dis + 1;
		}
	}
	int t;
	cin >> t;
while (t--)
{
	/* code */
	int i;
	cin >> i;
	for (int p = 0; p < i * 4;p++)
	{
		bj[0][dis[i]] = bj[1][dis[i]] = 0;
	}
	ans[0] = ans[1] = 0;
	while(i--)
	{
		int tor;
		cin >> tor;
		while(bj[tor][dis[ans[tor]]])
			ans[tor]++;
		t = dis[ans[tor]];
		cout << tor / max_dis << " " << tor % max_dis << endl;
		bj[1][tor] = 1;
		for (int o = 0; o < 4;o++)
		{
			bj[0][nxt(tor, o)] = 1;
		}
	}
}

}

// using uint = unsigned;
// using bol = bool;

// const uint T = 2000;
// const uint R = 200000;

// uint Ord[R + 5];		//各个网格到0，0的距离
// uint Nxt(uint p, uint o)
// {
// 	uint x = p / T, y = p % T;
// 	if (o & 1)y = y / 3 * 3 + 3 - y % 3;
// 	if (o & 2)x = x / 3 * 3 + 3 - x % 3;
// 	return x * T + y;
// }

// bol G[2][T * T]; uint Ans[2];

// int main()
// {
// 	//初始化表格并压缩成1维数组
// 	// 由哈夫曼法则知x+y = d(即到达(x,y)的最小距离，设d为i
// 	//x就是x轴坐标，i-x = y
// 	//tp表示第几张桌子
// 	//由于题目与数组方向不同，所以xy反转
// 	for (uint i = 2, tp = 0; i < T && tp < R; i++)
// 		if (i % 3 == 2)//处理左下角
// 		{
// 			for (uint x = 1; x < i && tp < R; x += 3)//+3跳到下一桌
// 				Ord[tp++] = x * T + i - x;			 //记录当前坐标
// 		}
// 		else if (!(i % 3))//距离为3的倍数（每桌的左上角和右下角）
// 		{
// 			for (uint x = 1; x <= i - 2 && tp < R; x++)//从x最小开始记录
// 				if (x % 3 == 1)
// 					Ord[tp++] = x * T + i - x;		//正常右下角.
// 				else if (x % 3 == 2)
// 					Ord[tp++] = x * T + i - x - 2,//上一桌的右上角，这里走到该格子需要绕一下，所以-2;
// 					Ord[tp++] = x * T + i - x;	  //左上角
// 			Ord[tp++] = (i - 1) * T + 1;		  //处理边界
// 		}

// 	uint t;scanf("%u", &t);
// 	while (t--)
// 	{
// 		uint q; scanf("%u", &q);
// 		for (uint i = 0; i < q * 4; i++)
// 			G[0][Ord[i]] = G[1][Ord[i]] = 0;
// 		Ans[0] = Ans[1] = 0;
// 		while (q--)
// 		{
// 			uint t; scanf("%u", &t);
// 			while (G[t][Ord[Ans[t]]])Ans[t]++;//有坐一直向后递推
// 			t = Ord[Ans[t]];//座位的坐标 = x*T+y
// 			printf("%u %u\n", t / T, t % T);
// 			G[1][t] = 1; //标记座位
// 			for (uint o = 0; o < 4; o++)
// 				G[0][Nxt(t, o)] = 1;//标记已坐座位
// 		}
// 	}
// 	return 0;
// }