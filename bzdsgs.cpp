#include <iostream>
#include <vector>
#include <string>

using namespace std;
int dew = 0;
int solution(int n) {
    // write code here
    dew += n / 2;
    if (n % 2 != 0)n += 1;
    if (n == 1)return dew;
    return solution(n / 2);


}

int main() {
    cout << (solution(7) == 6) << endl;
    cout << (solution(14) == 13) << endl;
    cout << (solution(1) == 0) << endl;

    return 0;
}