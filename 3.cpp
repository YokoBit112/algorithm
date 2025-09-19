#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool sa(const vector<string>& map, int x, int y) {
    int n = map.size();
    int m = map[0].size();
    if (x - 1 < 0 || map[x - 1][y] == 'W') return true;
    if (x + 1 >= n || map[x + 1][y] == 'W') return true;
    if (y - 1 < 0 || map[x][y - 1] == 'W') return true;
    if (y + 1 >= m || map[x][y + 1] == 'W') return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    vector<string> res = map;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'B' && !sa(map, i, j)) {
                res[i][j] = 'W';
            }
        }
    }
    for (int i = 0; i < res.size();i++) {
        cout << res[i] << endl;
    }

    return 0;
}