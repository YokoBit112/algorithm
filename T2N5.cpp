#include <iostream>

using namespace std;

class Square {
private:float r, p, s;
public:
	Square(float d = 0) {
		if (d == 0)r = 0;
		else r = d;
	}
	void perimeter(){p = r * 4;}
	void area() { s = r * r; }
	void print() {
		cout << "�߳���" << r << endl << "�ܳ���" <<p<< endl << "�����" << s << endl;
	}
};

int main(void)
{
	Square square(4.0);
	square.perimeter();
	square.area();
	square.print();
	return 0;
}