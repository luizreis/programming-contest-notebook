#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> adj[100010], ts;
int vis[100010], n, m, t, a, b;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v:adj[u]) dfs(v);
}

void visit(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v:adj[u]) visit(v);
    ts.pb(u);
}

void toposort() {
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++)
        if (!vis[i]) visit(i);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        ts.clear();
        for (int i=1; i<=n; i++) adj[i].clear();
        for (int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
        }
        toposort();
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        reverse(ts.begin(), ts.end());
        for (auto i:ts)
            if (!vis[i]) dfs(i), ans++;
        printf("%d\n", ans);
    }
    return 0;
}
