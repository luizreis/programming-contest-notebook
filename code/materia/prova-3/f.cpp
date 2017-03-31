#include <bits/stdc++.h>
using namespace std;

const int N = 100010;  // limit for array size
int n;  // array size
int t[2*N][26];
int h;
char d[N];

void calc(int p, int k) {
    if (d[p] == 0) {
        for (int i=0; i<26; i++)
            t[p][i] = t[p<<1][i] + t[p<<1|1][i];
    } else {
        int novo[26];
        for (int i=0; i<26; i++) {
            novo[(i+d[p])%26] = t[p][i];
        }
        for (int i=0; i<26; i++)
            t[p][i] = novo[i];
    }
}

void apply(int p, int value, int k) {
    int novo[26];
    for (int i=0; i<26; i++) {
        novo[(i+value)%26] = t[p][i];
    }
    for (int i=0; i<26; i++)
        t[p][i] = novo[i];
    if (p < n) d[p] = (d[p]+value)%26;
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

int query(int l, int r, int res[26]) {
    push(l, l + 1);
    push(r - 1, r);
    memset(res, 0, sizeof(int)*26);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            for (int i=0; i<26; i++) res[i] += t[l][i];
            l++;
        }
        if (r&1) {
            --r;
            for (int i=0; i<26; i++) res[i] += t[r][i];
        }
    }
}

int m;
char str[100100];

int main() {
    int a, b, c;
    char cmd[2];
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    for (int i=0; i<n; i++) t[i+n][str[i]-'a'] = 1;
    h = sizeof(int) * 8 - __builtin_clz(n);
    memset(d, 0, sizeof(d));
    build(0, n);
    for (int i = 0; i < m; i++) {
        scanf("%s %d %d", cmd, &a, &b);
        if (cmd[0] == 'M') {
            int ans[26];
            query(a-1, b, ans); // open right interval
            for (int i=0; i<26; i++) {
                if (i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        } else if (cmd[0] == 'A') {
            scanf("%d", &c);
            modify(a-1, b, c); // open right interval
        }
    }
    return 0;
}
