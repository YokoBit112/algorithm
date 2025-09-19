#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort1(int *arr,int n)
{
	for (int i = 0; i != n; i++)
	{
		for(int p = i + 1; p != n; p++)
		{
			if (arr[i] > arr[p])
			{
				int temp = arr[i];
				arr[i] = arr[p];
				arr[p] = temp;
			}
		}
	}
	for (int i = 0; i != n; i++)
	{
		printf("%d", arr[i]);
	}
}

int main(void)
{
	int a[10] = { 1,5,2,4,3 };
	sort1(a, 5);
}