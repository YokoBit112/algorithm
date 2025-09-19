#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1),f(n + 1),list;
    int tem;
    
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    for (int i = 0; i < n; ++i) { cin >> f[i]; }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        list.push_back(i + 1);
        sum += a[i];
    }
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        cin >> tem;
        list.push_back(tem);
        sum += a[tem-1];
            while (sum > m&&!list.empty())
            {
                sum -= a[list[0] - 1];
                list.erase(list.begin());
            }
        
        auto b = find(list.begin(), list.end(), f[tem-1]);
        if (b != list.end())cnt++;
    }
    cout << cnt << endl;
    return 0;
}