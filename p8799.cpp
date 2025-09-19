#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ll long long

int n, q;
unordered_map<int, bool> hash1;
int cl[200001],pd[200001], cx;

int main(void)
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> cl[i];
		pd[cl[i]]++;
	}
	sort(cl, cl + n);
	for (int i = 0; i < n; i++)
	{
		if (i >0&&cl[i] == cl[i - 1] )continue;
		for (int p = cl[i]; p <= cl[n - 1]; p += cl[i])
		{
			if (!pd[p])continue;
			if (pd[p] == 1 && p == cl[i])continue;
			hash1[p / cl[i]] = 1;
		}
	}
	while(q--)
	{
		cin >> cx;
		if (hash1[cx])cout << "YES" << endl;
		else cout << "NO"<<endl;
	}
}