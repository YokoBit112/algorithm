#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long ll;
int a[1024][1024];
int main() 
{
    int n, m, xa, ya, xb, yb;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        ++a[xa][ya];
        --a[xb + 1][ya];
        --a[xa][yb + 1];
        ++a[xb + 1][yb + 1];
    }
    for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
        printf("%d%c", a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1], j == n ? '\n' : ' ');
    return 0;
}