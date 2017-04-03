#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int res = 1, base = 1378;
    while (n) {
        if (n&1) res = (res*base)%10;
        n>>=1;
        base = (base*base)%10;
    }
    printf("%d\n", res%10);
    return 0;
}
