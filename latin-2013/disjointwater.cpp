#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

vector<int> adj[1001];
int N, n, c, p, u, v, vis[1001], ans[1001];

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

int verifica(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int ac = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        //ans[adj[u][i]] = 0;
        //printf("pai %d(%d) filho %d(%d)\n", u, dom[u], adj[u][i], dom[adj[u][i]]);
        if (u == dom[adj[u][i]])
            ac += 1 + verifica(adj[u][i]);
    }
    return ac;
}

int main() {
    while(scanf("%d %d", &c, &p) != EOF) {
        n = c;
        int res = (c*(c-1))/2;
        for (int i = 0; i <= c; i++) adj[i].clear();
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        dominators(1);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= c; i++) 
            if (dom[i] > 1) ans[dom[i]] = 1;
        for (int i = 2; i <= c; i++) {
            if (ans[i]) {
                //printf("chamando roe pra  %d\n", i);
                int count = verifica(i);
                //printf("res %d count %d\n", res, count);
                res -= ((count+1)*(count))/2;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
