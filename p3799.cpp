#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ll long long
unordered_map<int, int> a;
ll Combination(ll n, ll m)
{
    ll res = 1;
    for (ll i = 1; i <= m; ++i)
    {
        res = res * (n - m + i) / i; // ÏÈ³Ëºó³ý
    }
    return res;
}

ll sum = 0;

int main(void)
{
    int n = 0, s;
    cin >> n;
    for (int i = 0; i != n; i++)
    {
        cin >> s;
        a[s]++;
    }
    for (int i = 2; i <= 5000; i++)
    {
        if (a[i] >= 2)
        {
            for (int p = 1; p <= i/2; p++)
            {
                if (a[p] != 0 && a[i - p] != 0)
                {
                    if (p != i-p)
                        sum += Combination(a[i], 2) * a[p] * a[i - p];
                    else
                        sum += Combination(a[p], 2)* Combination(a[i],2);
                }
                sum %= 1000000007;
            }
        }
    }
    cout << sum;
    return 0;
}
