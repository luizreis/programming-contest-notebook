#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
using namespace std;

vector<int> G[200002];
queue<int> Q;
int vis[200002];
int dist[200002];
int match[200002];
int n, m, q, p, size;

int bfs () {
    for (int u = 1; u <= n; u++) {
        if (!match[u]) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INF;
        }
    }
    dist[0] = INF;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[0]) {
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return dist[0] != INF;
}

int dfs(int u) {
    if (u) {
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return 1;
                }
            }
        }
        dist[u] = INF;
        return 0;
    }
    return 1;
}

int hopcroft_karp() {
    memset(match, 0, sizeof(match));
    int size = 0;
    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (match[u] == 0) {
                if (dfs(u)) size++;
            }
        }
    }
    return size;
}

int main () {
    scanf("%d %d", &n, &m);
    size = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &q);
        for (int j = 0; j < q; j++) {
            scanf("%d", &p);
            p += 100000;
            G[i].push_back(p);
            G[p].push_back(i);
        }
    }
    printf("%d\n", hopcroft_karp());
    return 0;
}
