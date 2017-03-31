#include <bits/stdc++.h>
using namespace std;

#define MMAX 51
#define NMAX 21

int n, m, o[] = {1, 10, 100, 1000, 10000};

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        int ans = 0;
        for (int i=0; i<m; i++) {
            int d, b, ac = 0, t;
            scanf("%d %d", &b, &d);
            for (int j=1; j<n; j++) {
                scanf("%d", &t);
                ac += t;
            }
            int w = 0;
            if (ac+d <= b) w = d;
            int j;
            for (j=4; j>=0; j--)
                if (ac + o[j] <= b) break;
            if (j >= 0 && o[j] != d) {
                ans += o[j]-w;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
