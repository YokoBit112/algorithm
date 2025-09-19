#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string a;
	vector<int> arr;
	int se[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	unordered_map<char, int> hash;
	cin >> a;
	for (int i = 0; i != a.size(); i++)
	{
		hash[a[i]]++;
	}
	for (auto &count : hash)
	{
		arr.push_back(count.second);
	}
	sort(arr.begin(), arr.end());
	int q = *(arr.end() - 1) - *arr.begin();
	bool s = true;
	for (int i = 0; i != 25; i++)
	{
		if (q == se[i])
		{
			s = false; break;
		}
		
	}
	if (!s)cout << "Lucky Word" << endl << q;
	else cout << "No Answer\n0";
	return 0;
}