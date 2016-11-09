#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int d, p, r, b, x, y, id;
int c[202];
int cc[202], qc[202][2];
bool vis[202];
vector<int> adj[202];
int mem[202][10010][2];

void conecta(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cc[id] += c[u];
    qc[id][(u<=100)?0:1]++;
    for (int i=0; i<adj[u].size(); i++) conecta(adj[u][i]);
}

int dp(int n, int b, int p) {
    if (n >= id) return 0;
    if (mem[n][b][p] != -1) return mem[n][b][p];
    int opc1 = 0, opc2 = 0;
    opc1 = qc[n][p] + dp(n+1, b, p);
    if (b >= cc[n])
        opc2 = qc[n][1-p] + dp(n+1, b-cc[n], p);
    mem[n][b][p] = max(opc1, opc2);
    return mem[n][b][p];
}

int main() {
    while (scanf("%d %d %d %d", &d, &p, &r, &b) != EOF) {
        id = 0;
        for (int i=0; i<202; i++) adj[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(cc, 0, sizeof(cc));
        memset(qc, 0, sizeof(qc));
        memset(mem, -1, sizeof(mem));
        for (int i=0; i<d; i++) scanf("%d", c+i+1);
        for (int i=0; i<p; i++) scanf("%d", c+i+101);
        for (int i=0; i<r; i++) {
            scanf("%d %d", &x, &y);
            adj[x].pb(y+100);
            adj[y+100].pb(x);
        }
        for (int i=1; i<=d; i++) if (!vis[i]) conecta(i), id++;
        for (int i=1; i<=p; i++) if (!vis[i+100]) conecta(i+100), id++;
        printf("%d %d\n", dp(0, b, 0), dp(0, b, 1));
    }
    return 0;
}
