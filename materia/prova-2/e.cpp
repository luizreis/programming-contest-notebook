#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;  // limit for array size
int t[2 * N], t2[2*N];
int n, q, a, b, c;

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
    for (int i = n - 1; i > 0; --i) t2[i] = min(t2[i<<1], t2[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    int p_ = p;
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
    p = p_;
    for (t2[p += n] = value; p > 1; p >>= 1) t2[p>>1] = min(t2[p], t2[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

int query2(int l, int r) {  // sum on interval [l, r)
    int res = 1000000;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t2[l++]);
        if (r&1) res = min(res, t2[--r]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", t+i+n);
        t2[i+n] = t[i+n];
    }
    build();
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            modify(b-1, c);
        } else {
            printf("%d\n", query(b-1, c)-query2(b-1, c));
        }
    }
    return 0;
}
