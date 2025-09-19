#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        ll current = 0;
        int k = 1;
        while (true) {
            ll g1 = (ll)k * (3 * k - 1) / 2;
            ll g2 = (ll)k * (3 * k + 1) / 2;
            if (g1 > i && g2 > i) break;
            int sign = (k % 2 == 1) ? 1 : -1;
            if (g1 <= i) current += sign * dp[i - g1];
            if (g2 <= i) current += sign * dp[i - g2];
            ++k;
        }
        dp[i] = (current % MOD + MOD) % MOD;
    }
    cout << dp[n];
    return 0;
}