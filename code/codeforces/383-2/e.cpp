#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n, a, b, f[202020], vis[202020];
pair<int, int> p[101010];
vector<int> adj[202020];

int dfs(int u, int c) {
    vis[u] = 1;
    f[u] = c;
    for (auto v:adj[u])
        if (!vis[v]) dfs(v, c^1);
}

int main() {
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        p[i].first = a;
        p[i].second = b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int m = 2*n;
    for (int i=1; i<=n; i++) {
        adj[2*i-1].pb(2*i);
        adj[2*i].pb(2*i-1);
        //printf("%d is adj to %d\n", 2*i, 2*i-1);
    }
    for (int i=1; i<=m; i++)
        if (!vis[i]) dfs(i, 0);
    for (int i=0; i<n; i++) printf("%d %d\n", f[p[i].first]+1, f[p[i].second]+1);
    return 0;
}

