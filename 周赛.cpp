#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, c;
int main() {

    cin >> a >> b >> c;
    ll s = a + b + c,m = max(a, max(b, c));
    if (m == s) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
