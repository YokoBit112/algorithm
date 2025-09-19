#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;



int main() {
    
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        bool aj = (a % 2), bj = (b % 2);
        if (!aj && bj) {
            cout << -1 << endl;
        }
        else if (aj && bj) {
            cout << a * b + 1<<endl;
        }
        else if (aj && !bj) {
            if (!((b / 2) % 2)) {
                cout << a * b / 2 + 2<<endl;
            }
            else cout << -1 << endl;
        }
        else {
            //!aj,!bj
            cout << a*b/2+2 << endl;
        }
    }
    return 0;
}
