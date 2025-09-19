#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<iomanip>
// 填上你觉得需要的其他头文件
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {cout << "I love Luogu!";}
    else if (T == 2) {cout << 2 + 4 << " " << 10 - 2 - 4;}
    else if (T == 3) {cout << 3 << endl << 12 <<endl<< 2;}
    else if (T == 4) { double a = 500; a /= 3; cout << fixed << setprecision(3) << a; }
    else if (T == 5) {cout << (220 + 260) / (12 + 20);}
    else if (T == 6) {cout << sqrt(6 * 6 + 9 * 9);}
    else if (T == 7) {cout << 110 << '\n' << 90 << '\n' << 0;}
    else if (T == 8) {cout << 10 * 3.141593 << endl  << 3.141593 * 25 << endl << 1.0*4/3 * 3.141593 * 125;}
    else if (T == 9) {int p = 1;for (int i = 0; i != 3; i++){p = (p + 1) * 2;}cout << p;}
    else if (T == 10) {cout << "9";}
    else if (T == 11) {cout << 1.0*100 / 3 ;}
    else if (T == 12) {cout << (int)'M' - 'A'+1 << endl << (char)('A'+18-1);}
    else if (T == 13) {cout << (int)(pow(4 / 3 * 3.141593 * (4 * 4 * 4 + 10 * 10 * 10), 1.0 * 1 / 3));}
    else if (T == 14) {cout << "50";}
    return 0;
}