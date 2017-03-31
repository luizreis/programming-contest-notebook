#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, m, time_s, vis[MAX], par[MAX], ans;
vector <pair<int, int> > bridge;
vector <int> adj[MAX];

int dfs(int u) {
    int low = time_s, cc = 0;
    vis[u] = time_s++;
    for (int i = 0; i < adj[u].size(); i++) {
        if (!vis[adj[u][i]]) {
            par[adj[u][i]] = u;
            int low_i = dfs(adj[u][i]);
            low = min(low, low_i);
            if (low_i > vis[u]) {
                bridge.push_back(make_pair(u, adj[u][i]));
                ans = 1; // if there is a bridge, set the answer
            }
        } else if (adj[u][i] != par[u]) {
            low = min(low, vis[adj[u][i]]);
        }
    }
    return low;
}

void get_bridges() {
    time_s = 1;
    ans = 0;
    bridge.clear();
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    dfs(1);
}

int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        int x, y, p = 0;
        for (int i = 0; i < MAX; i++) adj[i].clear();
        
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        get_bridges();
        
        if (!ans) printf("S\n");
        else printf("N\n");
    }
}
