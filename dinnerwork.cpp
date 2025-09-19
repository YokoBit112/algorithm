#include <iostream>

void sort(int *a,int *b,int *c)
{
	int temp;
	while (!(*a >= *b && *b >= *c))
	{
		if (*a < *b)
		{
			temp = *a;
			*a = *b;
			*b = temp;
		}
		if (*b < *c)
		{
			temp = *b;
			*b = *c;
			*c = temp;
		}
	}
}

int main(void)
{
	int a, b, c;
	std::cin >> a >> b >> c;
	sort(&a, &b, &c);
	std::cout << a << b << c;
}