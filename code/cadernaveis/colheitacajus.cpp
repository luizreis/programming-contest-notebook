#include <bits/stdc++.h>
using namespace std;

int mat[1001][1001], ac[1001][1001];
int l, c, m, n, ans;

int main() {
    scanf("%d %d %d %d", &l, &c, &m, &n);
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= c; j++)
            scanf("%d", &mat[i][j]);
    ans = 0;
    // sentinel to avoid segfault (dp base)
    for (int i = 0; i < l; i++)
        ac[i][0] = ac[0][i] = 0;
    
    // dp
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= c; j++)
            ac[i][j] = ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1] + mat[i][j];
            
    // compute max sum based on sum for 
    for (int i = m; i <= l; i++)
        for (int j = n; j <= c; j++)
            ans = max(ans, ac[i][j] - ac[i-m][j] - ac[i][j-n] + ac[i-m][j-n]);
    printf("%d\n", ans);
}
