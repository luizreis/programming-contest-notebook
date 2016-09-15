#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int c, e, l, p, a, b;
int vis[51];

void bfs(int v, int p_) {
    queue< pair<int, int> > fila;
    fila.push(make_pair(v, p_));
    while (!fila.empty()) {
        int u = fila.front().first;
        int ped = fila.front().second;
        fila.pop();
        if (!vis[u]) {
            vis[u] = 1;
            if (ped) {
                for (int i = 0; i < adj[u].size(); i++) {
                    fila.push(make_pair(adj[u][i], ped-1));
                }
            }
        }
    }
}

int main () {
    int test = 1;
    while (scanf("%d %d %d %d", &c, &e, &l, &p) && (c || e || l || p)) {
        printf("Teste %d\n", test++);
        for (int i = 1; i <= c; i++) adj[i].clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(l, p);
        int fir = 1;
        for (int i = 1; i <= c; i++) {
            if (vis[i] && i != l) {
                if (!fir) printf(" ");
                else fir = 0;
                printf("%d", i);
            }
        }
        printf("\n\n");
    }
    return 0;
}
