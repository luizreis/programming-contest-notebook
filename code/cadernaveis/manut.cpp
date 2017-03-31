#include <cstdio>
#include <cstring>
#include <vector>

#define MAX 401

using namespace std;

int n, m, time_s, vis[MAX], ans[MAX];
vector <int> adj[MAX];

int dfs(int u) {
    int low = time_s, cc = 0;
    vis[u] = time_s++;
    for (int i = 0; i < adj[u].size(); i++) {
        if (!vis[adj[u][i]]) {
            cc++;
            int low_i = dfs(adj[u][i]);
            low = min(low, low_i);
            if (vis[u] <= low_i && (u != 1 || cc > 1)) ans[u] = 1;
        } else {
            low = min(low, vis[adj[u][i]]);
        }
    }
    return low;
}

void get_art() {
    time_s = 1;
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    dfs(1);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int t = 1; n; ++t) {
        int x, y, p = 0;
        for (int i = 0; i < MAX; i++) adj[i].clear();
        
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        get_art();
        
        printf("Teste %d\n", t);
        for (int i = 1; i <= n; i++) {
            if (ans[i]) {
                if (p++) printf(" ");
                printf("%d", i);
            }
        }
        if (!p) printf("nenhum");
        printf("\n\n");
        scanf("%d %d", &n, &m);
    }
}

