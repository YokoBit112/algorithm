#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int i = 0, sum = 0;
    while (sum <= 2021)
    {
        i++;
        sum += i * 21;
        cout << sum << " ";
    }
    return 0;
}


/*
ll l, w, h, n = 2021041820210418, cnt = 0;
    vector<ll> pa;
    for (l = 1; l*l<n; l++)
    {
        if (n % l)continue;
        pa.push_back(l);
        if (n / l != l)pa.push_back(n / l);
    }
    int m = pa.size();
    for (int i = 0; i < m; i++)
    {
        for (int p = 0; p < m; p++)
        {
            for (int q = 0; q < m; q++)
            {
                if (pa[i] * pa[q] * pa[p] == n)cnt++;
            }
        }
    }
    cout << cnt << endl;
*/


/*
map<pair<double, double>, bool> lis;
    double k, b;
    int cnt = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int p = 0; p < 21; p++)
        {
            for (int o = 0; o < 20; o++)
            {
                for (int q = 0; q < 21; q++)
                {
                    if (i == o || p == q)continue;
                    k = (double)(q - p) / (o - i);
                    b = (double)(p * o - q * i) / (o - i);
                    if (lis[{k, b}] == 0)
                    {
                        cnt++;
                        lis[{k, b}] = 1;

                    }
                }
            }
        }
    }
    cout << cnt+41;
*/

/*
   int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = 2021;
    }
    int i = 1,temp;
    while (1)
    {
        temp = i;
        while (temp)
        {
            a[temp % 10]--;
            if (a[temp%10] < 0) {
                cout << i;
                return 0;
            }
            temp /= 10;

        }
        i++;
    }
*/
/*
    string ans[] = {
        "3182", // 双引号中替换为 A 题的答案
        "40257", // 双引号中替换为 B 题的答案
        "2430", // 双引号中替换为 C 题的答案
        "The answer of task D", // 双引号中替换为 D 题的答案
        "The answer of task E", // 双引号中替换为 E 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
*/