#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int p = 0; p <= 9; p++)
		{
			for (int q = 0; q <= 9; q++)
			{
				if (i == p && i == q);
				else {
					if ((i * 100 + p * 10 + q) == (i * i*i + p *p* p + q*q * q))
					{
						printf("%d%d%d\n", i, p, q);
					}
				}
			}
		}
	}
	return 0;
}