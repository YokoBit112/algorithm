#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int p = 0; p < (1 << n); p++)
		{
			cout << (i | p) << " ";
			//printf("%d ", ((i | p) != ((1 << n) - 1) ? 0 : 1));
		}
		printf("\n");
	}
	return 0;
}