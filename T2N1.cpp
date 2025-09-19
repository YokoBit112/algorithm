#include <iostream>

using namespace std;

int m, n;

int main(void)
{
	cout << "请输入图形的行数和列数：";
	cin >> n >> m;
	for (int i = 0; i != n; i++)
	{
		for (int p = 0; p < i; p++)
		{
			cout << " ";
		}
		for (int p = 0; p != m; p++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}