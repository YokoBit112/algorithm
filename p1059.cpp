#include<iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> a;
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.insert(temp);
	}
	cout << a.size() << endl;
	for (int i = 1;i<=1000;i++)
	{
		if (a.find(i) != a.end())cout << i << " ";
	}
}