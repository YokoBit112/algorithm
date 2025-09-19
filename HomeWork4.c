#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long 
void print_pascal_triangle(int n) {
	int arr[11][11] = { 0 };
	int i = 0;
	int j = 0;
	//loading triangle
	for (i = 0; i < n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (i = 3; i <= n; i++)
	{
		for (j = 1; j < i - 1; j++)
		{
			arr[i - 1][j] = arr[i - 1 - 1][j] + arr[i - 1 - 1][j - 1];
		}
	}
	//output triangle
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)printf("   ");
		for (j = 0; j <= i; j++)
		{
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
	//loading/output a[n]
	int hang = 0;
	int s = 20;
	for (int i = 1; s - i >= 0; i++)
	{
		s -= i;
		hang++;
	}
	printf("第20位数为：%d", arr[hang][s-1]);
}
int main()
{
	int list = 10;
	print_pascal_triangle(list);
	return 0;
}