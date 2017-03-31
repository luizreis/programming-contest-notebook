#include <bits/stdc++.h>
using namespace std;

int m, a, b;
char cmd[2];

typedef struct { int h, e, r; } node;

const int N = 100010;  // limit for array size
int n;  // array size
node t[2 * N];
int h;
char d[N];

void calc(int p, int k) {
    if (d[p] == 0) {
        t[p].h = t[p<<1].h + t[p<<1|1].h;
        t[p].e = t[p<<1].e + t[p<<1|1].e;
        t[p].r = t[p<<1].r + t[p<<1|1].r;
    } else {
        for (int i = 0; i < d[p]; i++) {
            int h = t[p].h, e = t[p].e, r = t[p].r;
            t[p].e = h;
            t[p].r = e;
            t[p].h = r;
        }
    }
}

void apply(int p, int value, int k) {
    for (int i = 0; i < value%3; i++) {
        int h = t[p].h, e = t[p].e, r = t[p].r;
        t[p].e = h;
        t[p].r = e;
        t[p].h = r;
    }
    if (p < n) d[p] = (d[p]+value)%3;
}

void build(int l, int r) {
    int k = 2;
    for (l += n, r += n-1; l > 1; k <<= 1) {
        l >>= 1, r >>= 1;
        for (int i = r; i >= l; --i) calc(i, k);
    }
}

void push(int l, int r) {
    int s = h, k = 1 << (h-1);
    for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
        apply(i<<1, d[i], k);
        apply(i<<1|1, d[i], k);
        d[i] = 0;
    }
}

void modify(int l, int r, int value) {
    if (value == 0) return;
    push(l, l + 1);
    push(r - 1, r);
    bool cl = false, cr = false;
    int k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
        if (cl) calc(l - 1, k);
        if (cr) calc(r, k);
        if (l&1) apply(l++, value, k), cl = true;
        if (r&1) apply(--r, value, k), cr = true;
    }
    for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
        if (cl) calc(l, k);
        if (cr && (!cl || l != r)) calc(r, k);
    }
}

int query(int l, int r, node &res) {
    push(l, l + 1);
    push(r - 1, r);
    res.h = res.e = res.r = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            res.h += t[l].h;
            res.e += t[l].e;
            res.r += t[l++].r;
        }
        if (r&1) {
            res.h += t[--r].h;
            res.e += t[r].e;
            res.r += t[r].r;
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        h = sizeof(int) * 8 - __builtin_clz(n);
		memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            t[i].h = t[i].e = t[i].r = 0;
            t[i+n].h = 1, t[i+n].e = 0, t[i+n].r = 0;
        }
        build(0, n);

        for (int i=0; i<m; i++) {
            scanf("%s %d %d", cmd, &a, &b);
            if (cmd[0] == 'C') {
                // conta
                node ans;
                query(a-1, b, ans);
                printf("%d %d %d\n", ans.h, ans.e, ans.r);
            } else {
                // muda
                modify(a-1, b, 1);
            }
        }
		printf("\n");
    }
    return 0;
}
