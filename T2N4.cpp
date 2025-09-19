#include <iostream>

using namespace std;

class Date {
private:
	int year, month, day;
public:
	Date() { year = 1; month = 1; day = 1; }
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
	}
	void print() {
		cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ";
	}
};
int main(void)
{
	Date national_day(1949,10,1);
	national_day.print();
	return 0;
}