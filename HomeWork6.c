#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int s[50000] = { 0 };
int sort(int arr[50000],int n,int w)
{
	int i, j;
	int temp;
	int ac = 1;
	while (ac) {
		ac = 0;
		for (i = 0; i < n; i++) {
			if (arr[i] > arr[i + 1]) {
				ac = 1;
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (w - arr[i] >= 0)
		{
			w -= arr[i];
			sum++;
		}
		else break;
	}
	return sum;
}

int sums(int arr[], int arr2[],int n,int m)
{
	int sum = 0;
	for (int i = 0; i != n; i++)
	{
		sum += arr[i];
	}
	for (int i = 0; i != m; i++)
	{
		sum += arr2[i];
	}
	return sum;
}

int main(void)
{
	int n, w,a,b,x,y;
	scanf("%d%d%d%d", &n, &w, &a,&b);
	int sum = a + b;
	for (int i = 0; i != n; i++)
	{
		scanf("%d%d", &x,&y);
		if (x > sum) {
			n--; i--;
		}
		else {
			s[i] = y;
		}
	}
	int sum1  = sort(s,n,w);
	printf("%d", sum1);
}