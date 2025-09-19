#include <iostream>
#define ll long long
using namespace std;
int n, m,a[100010];
ll sum;
double sua, b[100010];
class count1 {
public:
	int count(ll su, int a[],int n){int s = 0;for (int i = 0; i != n; i++){if (a[i] > su)s++;}return s;}
	double count(double su, double a[], int m) {int s = 0; for (int i = 0; i != n; i++) { if (b[i] > su)s++; }return s;}
};

int main(void)
{
	count1 count1;
	cout << "请输入整数数组的大小：" ;cin >> n;
	cout << "请输入" << n << "个整数：";for (int i = 0; i != n; i++){cin >> a[i];sum += a[i];}sum /= n;
	cout << "请输入实数数组的大小：";cin >> m;
	cout << "请输入" << m << "个实数：";for (int i = 0; i != m; i++){cin >> b[i];sua += b[i];}sua /= m;
	cout <<"整数组中大于平均值的个数为："<< count1.count(sum, a,n) << endl << "实数组中大于平均值的数的个数为：" << count1.count(sua, b,m) << endl;
	return 0;
}