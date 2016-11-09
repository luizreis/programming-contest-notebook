#include <bits/stdc++.h>
using namespace std;

int n, k, x, a, b;
char cmd[2];

const int N = 1e5+1;  // limit for array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1]*t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p]*t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = res*t[l++];
        if (r&1) res = res*t[--r];
    }
    return res;
}


int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        memset(t, 0, sizeof(t));
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            t[i+n] = (x<0?-1:(x>0?1:0));
        }
        build();
        for (int i=0; i<k; i++) {
            scanf("%s %d %d", cmd, &a, &b);
            if (cmd[0] == 'C') modify(a-1, (b<0?-1:(b>0?1:0)));
            else if (cmd[0] == 'P') {
                int r = query(a-1, b);
                printf("%c", (r<0?'-':(r>0?'+':'0')));
            }
        }
        printf("\n");
    }
    return 0;
}
