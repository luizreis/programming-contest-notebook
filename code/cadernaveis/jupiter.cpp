#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 100010

using namespace std;

long long tree[100010];
long long vect[100010];
long long b, p, l, n;

long long gcd (long long a, long long b) {
    while (b) { long long t = a%b; a = b; b = t; }
    return a;
}

long long lcm (long long a, long long b) {
    return a / gcd(a, b)*b;
}

long long powermod(long long a, long long b, long long m) {
    long long ret = 1;
    while (b) {
        if (b&1) ret = (ret*a) % m;
        a = (a*a) % m;
        b>>=1;
    }
    return ret % m;
}

long long extended_euclid(long long a, long long b, long long &x, long long &y) {
    long long xx = y = 0;
    long long yy = x = 1;
    while (b) {
        long long q = a/b;
        long long t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

long long mod_inverse (long long a, long long n) {
    long long x, y;
    long long g = extended_euclid(a, n, x, y);
    if (g>1) return -1;
    return (x+n) % n;
}

void update(long long idx ,long long val){
    long long old = vect[idx];
    vect[idx] = val;
    while (idx <= MAX){
        tree[idx] = (tree[idx] + p - old + val) % p;
        idx += (idx & -idx);
    }
}

long long read(long long idx){
    long long sum = 0;
    while (idx > 0){
        sum = (sum + tree[idx]) % p;
        idx -= (idx & -idx);
    }
    return sum;
}

int main () {
    while (1) {
        scanf("%lld %lld %lld %lld", &b, &p, &l, &n);
        if (!b && !p && !l && !n) break;
        memset(tree, 0, sizeof(tree));
        memset(vect, 0, sizeof(vect));
        //printf("byte(%d) prime(%d) length(%d) queries(%d)\n", b, p, l, n);
        for (long long i = 0; i < n; i++) {
            // comandos
            char cmd[2];
            long long x, y;
            scanf("%s %lld %lld", cmd, &x, &y);
            //printf("%c, byte/init(%d), value/end(%d)\n", cmd[0], x, y);
            if (cmd[0] == 'E') {
                // calc base
                long long base = powermod(b, l-x, p);
                //printf("base = %lld\n", base);
                long long value = (y*base) % p;
                //printf("value = %lld(%lld)\n", value, y*base);
                update(x, value);
            } else {
                long long interval = (read(y) + p - read(x-1)) % p;
                //printf("interval sum %lld %lld = %lld - %lld = %lld\n", y, x-1, read(y), read(x-1), interval);
                long long mod_inv = mod_inverse(powermod(b, l-y, p), p);
                //printf("mod inv = %lld\n", mod_inv);
                long long hash = interval * mod_inv;
                printf("%lld\n", hash % p);
            }
        }
        printf("-\n");
    }
    return 0;
}
