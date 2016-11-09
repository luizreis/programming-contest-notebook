#include <bits/stdc++.h>
using namespace std;

int w[2020], c[2020], d[2020];
int n;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", w+i);
    c[n] = d[n] = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=i+1; j<=n; j++) {
            if ((j==n || w[j]>w[i]) && d[j]+1>d[i]) d[i] = d[j]+1;
            if ((j==n || w[j]<w[i]) && c[j]+1>c[i]) c[i] = c[j]+1;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, c[i]+d[i]-1);
    printf("%d\n", ans);
    return 0;
}

