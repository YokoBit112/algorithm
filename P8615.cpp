#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long

using namespace std;

unordered_set<int> lolg;

bool cf(int k)
{
	int f = 10;
	for (int i = 0; i < 5; i++)
	{
		int x = k / f;
		int y = k % f;
		f *= 10;
		if (lolg.find(x) != lolg.end() && lolg.find(y) != lolg.end())
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= 1000; i++)
	{
		lolg.insert(i * i);
		if (i * i < a)continue;
		else if (i * i > b)break;
		else {
			if (cf(i * i))cout << i * i << endl;
			else continue;
		}
	}
	return 0;
}