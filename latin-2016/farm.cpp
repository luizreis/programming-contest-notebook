#include <bits/stdc++.h>
using namespace std;

int n, c, s, x[101], cm, atu;

int main() {
    scanf("%d %d %d", &n, &c, &s);
    memset(x, 0, sizeof(x));
    atu = 0;
    x[0] = 1;
    for (int i=0; i<c; i++) {
        scanf("%d", &cm);
        atu = (atu+cm+n)%n;
        x[atu]++;
    }
    printf("%d\n", x[s-1]);
    return 0;
}
