#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

#define MAX 5001

using namespace std;

int n, m, k, ans[MAX];
vector<int> adj[MAX];

int N;
vector<int> pred[MAX], bucket[MAX];
int semi[MAX], parent[MAX], vert[MAX];
int dom[MAX], label[MAX], anc[MAX];

void dfs(int u) {
    semi[u] = ++N;
    vert[N] = label[u] = u;
    anc[u] = 0;
    for (int i=0;i<(int)adj[u].size();i++) {
        int w = adj[u][i];
        if (semi[w]==0) {
            parent[w] = u;
            dfs(w);
        }
        pred[w].push_back(u);
    }
}

void compress(int u) {
    if (anc[anc[u]] != 0) {
        compress(anc[u]);
        if (semi[label[anc[u]]] < semi[label[u]])
            label[u] = label[anc[u]];
        anc[u] = anc[anc[u]];
    }
}

int eval(int u) {
    if (anc[u]==0) return u;
    compress(u);
    return label[u];
}

void link(int u, int v) {
    anc[v] = u;
}

void dominators(int ini) {
    for (int i=0;i<=n;i++) {
        pred[i].clear();
        bucket[i].clear();
        semi[i] = 0;
    }

    N=0;
    dfs(ini);
    for (int i=N;i>=2;i--) {
        int w = vert[i];
        for (int j=0;j<(int)pred[w].size();j++) {
            int v = pred[w][j];
            int u = eval(v);
            if (semi[u] < semi[w])
                semi[w] = semi[u];
        }
        bucket[vert[semi[w]]].push_back(w);
        link(parent[w],w);
        for (int j=0;j<(int)bucket[parent[w]].size();j++) {
            int v = bucket[parent[w]][j];
            int u = eval(v);
            dom[v] = (semi[u] < semi[v]) ? u : parent[w];
        }
        bucket[parent[w]].clear();
    }
    for (int i=2;i<=N;i++) {
        int w = vert[i];
        if (dom[w] != vert[semi[w]])
            dom[w] = dom[dom[w]];
    }
    dom[ini] = 0;
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) adj[i].clear();
        
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
        }
        
        dominators(1);
        
        int dc = 0;
        for (int i = 1; i <= n; i++)
            if (dom[i] != 0) ans[dc++] = dom[i];
        
        sort(ans, ans + dc);
        dc = unique(ans, ans + dc) - ans;
        printf("%d\n", dc);
        for (int i = 0; i < dc; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
