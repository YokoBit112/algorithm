#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long
char a[1000000];
int find(char a[], char b)
{
	int i = 0, max = 0;
	while (a[i] != '\0')
	{
		while (a[i++] != b && a[i] != '\0');
		int c = i + 1;
		while (a[c] != b && a[c] != '\0')c++;
		if (max < c - i)max = c - i;
		//printf("%d\n%d", c, i);
		i = c - 1;
	}
	return max;
}

ll main(void)
{
	char b;
	scanf("%s\n", a);
	scanf("%c", &b);
	printf("%d", find(a, b));
}