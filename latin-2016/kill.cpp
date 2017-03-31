#include <bits/stdc++.h>
using namespace std;

#define MAXN 110
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int n, vw, cnt = 0, max_flow;
int cap[MAXN][MAXN];
pair<int, int> v[MAXN];
vector<int> adj[MAXN];

int findpath() {
    queue<int> q;
    int f[MAXN], v[MAXN];
    memset(f, -1, sizeof(f));
    memset(v, 0, sizeof(v));
    q.push(0);
    v[0] = 1;
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        for (auto u: adj[w]) {
            if (!v[u] && cap[w][u] > 0) {
                q.push(u);
                v[u] = 1;
                f[u] = w;
                if (u == MAXN-1) goto end_while;
            }
        }
    }
end_while:
    int w = MAXN-1;
    int pathcap = INF;
    while (f[w] != -1) {
        int p = f[w];
        pathcap = min(pathcap, cap[p][w]);
        w = p;
    }
    w = MAXN-1;
    while (f[w] != -1) {
        int p = f[w];
        cap[p][w] -= pathcap;
        cap[w][p] += pathcap;
        w = p;
    }
    if (pathcap == INF) return 0;
    return pathcap;
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d %d", &(v[i].first), &(v[i].second));
    for (int i=1; i<=n; i++) {
        vw = max_flow = 0;
        for (int j=0; j<MAXN; j++) adj[j].clear();
        memset(cap, 0, sizeof(cap));
        for (int j=1; j<=n; j++) {
            if (i == j) continue;
            if (v[j].first == i || v[j].second == i) {
                vw++;
            } else {
                adj[j].pb(v[j].first+n); adj[v[j].first+n].pb(j);
                adj[j].pb(v[j].second+n); adj[v[j].second+n].pb(j);
                cap[j][v[j].first+n] = cap[j][v[j].second+n] = 1;
                cap[v[j].first+n][j] = cap[v[j].second+n][j] = 0;
            }
        }
        for (int j=1; j<=n; j++) {
            adj[0].pb(j); cap[0][j] = 1;
            adj[j+n].pb(MAXN-1); cap[j+n][MAXN-1] = vw-1;
        }
        cap[v[i].first+n][MAXN-1] = cap[v[i].second+n][MAXN-1] = vw-2;
        while (1) {
            int pathcap = findpath();
            if (pathcap == 0) break;
            max_flow += pathcap;
        }
        if (max_flow < n-1-vw) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

