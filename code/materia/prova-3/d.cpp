#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    long long np = 0, cp = 0;
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int n, c;
        scanf("%d %d", &n, &c);
        np += n*c;
        cp += c;
    }
    printf("%.4lf\n", (double)np/(cp*100.0));

    return 0;
}
