#include <iostream>
#include <cmath>
using namespace std;

int n, a[100010], min1 = 1e10;

int main(void)
{
	cout << "请输入整数个数：";
	cin >> n;
	cout << "请输入" << n << "个整数:";
	for (int i = 0; i != n; i++)
	{
		cin >> a[i];
		min1 = min(a[i], min1);
	}
	cout << "这些整数中的最小值为：" << min1 << endl;
	return 0;
}