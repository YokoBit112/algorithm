#include <iostream>

using namespace std;

int m, n;

int main(void)
{
	cout << "������ͼ�ε�������������";
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