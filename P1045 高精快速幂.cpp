#include <bits/stdc++.h>
using namespace std;
int a[505], b[505], t[505], i, j;

void mult(int x[], int y[])  // �߾��ȳ˷�
{
    memset(t, 0, sizeof(t));
    for (i = 1; i <= x[0]; i++) {
        for (j = 1; j <= y[0]; j++) {
            if (i + j - 1 > 500) continue;
            t[i + j - 1] += x[i] * y[j];
            t[i + j] += t[i + j - 1] / 10;
            t[i + j - 1] %= 10;
            t[0] = i + j;
        }
    }
    memcpy(b, t, sizeof(b));
}

void ksm(int p)  // ������
{
    if (p == 1) {
        memcpy(b, a, sizeof(b));
        return;
    }
    ksm(p / 2);  //(2^(p/2))^2=2^p
    mult(b, b);  // ��bƽ��
    if (p % 2 == 1) mult(b, a);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int p;
    cin >> p;
    a[0] = 1;  // ��¼a�����λ��
    a[1] = 2;  // ��2����ƽ��
    b[0] = 1;  // ��¼b�����λ��
    b[1] = 1;  // ������
    ksm(p);
    long long x = ceil((double)p * log10(2));
    cout << x << endl;
    int hs = 0;
    for (i = 500; i >= 1; i--) {
        if (i == 1) {
            cout << b[i] - 1 << '\n';  // ���һλ��1
        }
        else
            cout << b[i];
        hs++;
        if (hs == 50) {
            cout << endl;
            hs = 0;
        }
    }
}
