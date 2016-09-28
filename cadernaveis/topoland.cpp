#include <bits/stdc++.h>
using namespace std;

int ntc, n, m, q, a, b;
char cmd[2];

const int N = 1e5+1;  // limit for array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}


int main() {
    scanf("%d", &ntc);
    for (int tc = 0; tc < ntc; tc++) {
        memset(t, 0, sizeof(t));
        printf("Testcase %d:\n", tc);
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            // read to segtree (start at index n)
            scanf("%d", t + n + i);
        }
        build();
        scanf("%d", &q);
        while (q--) {
            scanf("%s", cmd);
            switch (cmd[0]) {
                case 'A':
                    scanf("%d", &a);
                    m += a;
                    break;
                case 'B':
                    scanf("%d %d", &a, &b);
                    modify(a, b);
                    break;
                case 'C':
                    scanf("%d %d", &a, &b);
                    // query interval is open at right
                    printf("%d\n", abs(m - query(a, b+1)));
                    break;
            }
        }
        printf("\n");
    }
}
