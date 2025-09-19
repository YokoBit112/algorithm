#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // 存储每个值在b数组中的索引位置
        vector<vector<int>> FRQ(n + 1);
        for (int i = 0; i < n; ++i) {
            FRQ[a[i]].push_back(i);
        }

        vector<int> b(n, 0);
        int cnt = 1;
        bool possible = true;

        for (int i = 1; i <= n; ++i) {
            if (FRQ[i].size() % i != 0) {
                possible = false;
                break;
            }

            int c = 0;
            while (c < FRQ[i].size()) {
                for (int v = 0; v < i; ++v) {
                    b[FRQ[i][c]] = cnt;
                    c++;
                }
                cnt++;
            }
        }

        if (possible) {
            for (int num : b) {
                cout << num << " ";
            }
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
