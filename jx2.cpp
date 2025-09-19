#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define ll long long
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> xc(n);
        for (int i = 0; i < n; ++i) {
            cin >> xc[i];
        }
        vector<ll> zs(m);
        for (int i = 0; i < m; ++i) {
            cin >> zs[i];
        }
        sort(xc.rbegin(), xc.rend());
        vector<ll> xcm(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            xcm[i] = xcm[i - 1] + xc[i - 1];
        }
        sort(zs.rbegin(), zs.rend());
        vector<ll> zsm(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            zsm[i] = zsm[i - 1] + zs[i - 1];
        }
        int max_y = min(m, k / 2);
        ll res = 0;
        for (int y = 0; y <= max_y; ++y) {
            int zx = k - 2 * y;
            int max_x = min(n, zx);
            ll tem = xcm[max_x] + zsm[y];
            if (tem > res) {
                res = tem;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
