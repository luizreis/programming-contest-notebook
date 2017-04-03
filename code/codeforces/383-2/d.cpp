#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n, m, W, x, y, cc;
int w[1010], b[1010];
vector<int> adj[1010];
int vis[1010];
vector<int> cj[1010];
int wc[1010], bc[1010];
int mem[1010][2010];

int dp(int i, int cap) {
    if (i>=cc) return 0;
    int &res = mem[cap][i];
    if (res != -1) return res;
    int opc1 = dp(i+1, cap);
    int opc2 = 0;
    if (cap - wc[i] >= 0) opc2 = bc[i] + dp(i+1, cap-wc[i]);
    int opc3 = 0;
    for (int u:cj[i]) {
        if (cap - w[u] >= 0) opc3 = max(opc3, b[u] + dp(i+1, cap - w[u]));
    }
    res = max(opc1, opc2);
    res = max(res, opc3);
    return res;
}

int dfs(int u) {
    vis[u] = 1;
    cj[cc].pb(u);
    wc[cc] += w[u];
    bc[cc] += b[u];
    for (auto v:adj[u])
        if (!vis[v]) dfs(v);
}

int main() {
    scanf("%d %d %d", &n, &m, &W);
    cc = 0;
    memset(vis, 0, sizeof(vis));
    memset(mem, -1, sizeof(mem));
    for (int i=1; i<=n; i++) scanf("%d", w+i);
    for (int i=1; i<=n; i++) scanf("%d", b+i);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i);
            cc++;
        }
    }
    printf("%d\n", dp(0, W));
    return 0;
}

