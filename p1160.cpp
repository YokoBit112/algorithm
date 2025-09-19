#include <bits/stdc++.h>

using namespace std;

struct node
{
	int l = 0, r = 0;
	bool remove = false;
};
vector<node> lis1t(100001);

int main(void)
{
	int n,k,p,tem;
	cin >> n; 

	for (int i = 0; i < n-1; i++)
	{
		cin >> k >> p;
		if (p == 0){
			if (lis1t[k].r == 0)
			{
			lis1t[i + 2].l = k;
			lis1t[k].r = i + 2;
			}
			else {
				lis1t[i + 2].r = lis1t[k].r;
				lis1t[lis1t[k].r].l = i + 2;
				lis1t[k].r = i + 2;
				lis1t[i + 2].l = k;
			}
		}
		else {
			if (lis1t[k].l == 0)
			{
			lis1t[k].l = i + 2;
			lis1t[i + 2].r = k;
			}
			else {
				lis1t[i + 2].l = lis1t[k].l;
				lis1t[lis1t[k].l].r = i + 2;
				lis1t[k].l = i + 2;
				lis1t[i + 2].r = k;
			}
			
		}
	}
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> k;
		lis1t[k].remove = 1;
	}
	int s = 1;
	while (lis1t[s].r != 0)
	{
		s = lis1t[s].r;
	}
	while (lis1t[s].l != 0)
	{
		if(lis1t[s].remove == 0)cout << s << " ";
		s = lis1t[s].l;
	}
	if(lis1t[s].remove == 0)cout << s;
}