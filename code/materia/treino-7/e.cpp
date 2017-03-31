#include <bits/stdc++.h>
using namespace std;

int n, f[41];

int main() {
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i=3; i<41; i++) f[i] = f[i-2] + f[i-1];
    while (scanf("%d", &n) && n) {
        printf("%d\n", f[n]);
    }
    return 0;
}
