#include <iostream>
#include <cmath>
using namespace std;

int n, a[100010], min1 = 1e10;

int main(void)
{
	cout << "����������������";
	cin >> n;
	cout << "������" << n << "������:";
	for (int i = 0; i != n; i++)
	{
		cin >> a[i];
		min1 = min(a[i], min1);
	}
	cout << "��Щ�����е���СֵΪ��" << min1 << endl;
	return 0;
}