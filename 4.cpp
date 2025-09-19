#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, int> hash;
	int n,tem;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tem;
		hash[tem]++;
	}
	
	for (auto& pair : hash)
	{
		pair.second %= 3;
		
	}
	for (auto& pair : hash)
	{
		int l = pair.first-1, r = pair.first+1;
		while (l > 0)
		{
			if (hash[l] > 0 && hash[r] > 0) {
				hash[l]--; hash[r]--; pair.second--;
				break;
			}
			l--; r++;
		}
	}
	for (auto& pair : hash)
	{
		if (pair.second){cout << "NO"; return 0;
	}
	}
	cout << "YES";
	return 0;
	
}