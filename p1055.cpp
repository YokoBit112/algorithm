#include <iostream>

using namespace std;



int main(void)
{
	string isbn,se = "0123456789X";
	cin >> isbn;
	int x = 1, sum = 0;
	for (int i = 0; i < isbn.size() - 1; i++)
	{
		if (isbn[i] == '-')continue;
		else {
			sum += (isbn[i] - '0')* x++;
		}
	}
	if (se[sum%11]==*(isbn.end()-1))cout << "Right";
	else
	{
		*(isbn.end() - 1) = se[sum % 11];
		cout << isbn;
	}
	return 0;
}