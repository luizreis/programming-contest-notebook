#include <bits/stdc++.h>
using namespace std;

int cr[101], vis[101], n, t, c;

int gcd(int a, int b) {
    while (b) { int t = a%b; a = b; b = t; }
    return a;
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int dfs(int r, int u) {
    if (vis[u] && u == r) return 0;
    else if (vis[u]) return -100000;
    vis[u] = 1;
    return 1+dfs(r, cr[u]);
}

int main() {
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    t = 1;
    for (int i=1; i<=n; i++) scanf("%d", cr+i);
    for (int i=1; i<=n; i++) {
        c = dfs(i, i);
        if (c < 0) {
            printf("-1\n");
            return 0;
        } else if (c == 0) c = 1;
        if (c&1) t = lcm(t, c);
        else t = lcm(t, c/2);
    }
    printf("%d\n", t);
    return 0;
}

