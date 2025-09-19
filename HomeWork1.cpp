#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
/*
void ForceSolution(ll n)//时间复杂度O（N！）
{
	count = 1; primes[0] = 2;
	printf("2 ");
	for (ll i = 3; i <= n; i++)
	{
		for (ll p = 0; p != count; p++)
		{
			if (i % primes[p] == 0)break;
			else if (p == count - 1) {
				primes[count++] = i;
				printf("%lld ", i);
				break;
			}
		}
	}
	printf("\n一共有%lld个素数", count);
}*/
bool isPrime[100000001];
int primes[100000001];
int count1 = 0;
vector<int> sa;
void linearSieve(int n) {//算超过1e8的数据会爆，更大的不会写了，投降
	for (int i = 0; i != n; i++)isPrime[i] = true;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i])
		{
			if (2024 % i == 0) {
				sa.push_back(i); cout << i << endl;
			}
			primes[count1++] = i;
		}
		for (int j = 0; j < count1 && i * primes[j] <= n; j++) {
			isPrime[i * primes[j]] = false;
			if (i % primes[j] == 0)
				break;
		}
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i != sa.size(); i++)cout << sa[i] << " ";
	linearSieve(n);
	return 0;
}