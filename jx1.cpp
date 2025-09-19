#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;
int t,n,m,k;
int main() {
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> diff(n + k + 2, 0);
        ll ans = 0;
        int pair = 0;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += diff[i];
            ll ne = a[i] - cnt;
            if (ne > 0) {
                int jx = i;
                int j = jx;
                ans += ne;
                diff[j] += ne;
                int end = j + k;
                if (end < n) {
                    diff[end] -= ne;
                }
                cnt += ne;
            }
            pair = i + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
