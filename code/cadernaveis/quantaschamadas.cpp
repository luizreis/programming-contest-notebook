#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sol(ll n, int m) {
    ll a, b, c, d, r;
    a = 1; b = 0; c = 0; d = 1;
    while (n) {
        if (n&1) {
            r = ((d*b) + (c*a)) % m;
            b = (d*(b+a) + (c*b)) % m;
            a = r;
        }
        r = (c*c + d*d) % m;
        d = (d * (2*c + d)) % m;
        c = r;
        n >>= 1;
    }
    return (a+b) % m;
}

int main() {
    ll n;
    int b, r, c = 0;
    while (scanf("%lld %d", &n, &b) && (n || b)) {
        //r = ((sol(n, b) % b) + b) % b;
        r = (((2*sol(n, b) - 1) % b) + b) % b;
        printf("Case %d: %lld %d %d\n", ++c, n, b, r);
    }
    return 0;
}
