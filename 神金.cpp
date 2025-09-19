#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> hash;
	string tem1; int tem2;long long res = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> tem1 >> tem2;
		hash[tem1] = tem2;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tem2 >> tem1;
		if (tem2 == 0)hash[tem1]--;
		else if (tem2 == 1 && hash[tem1]>0) {
			res++;
			hash[tem1] = 0;
		}
	}
	cout << res;
	return 0;
}