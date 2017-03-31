#include <bits/stdc++.h>
using namespace std;

long long t, n, s, tmp1;
char tmp[11];

int main() {
    while (scanf("%lld %lld", &t, &n) && t) {
        s = 0;
        for (int i=0; i<t; i++) {
            scanf("%s %lld", tmp, &tmp1);
            s += tmp1;
        }
        printf("%lld\n", 3*n-s);
    }
    return 0;
}
