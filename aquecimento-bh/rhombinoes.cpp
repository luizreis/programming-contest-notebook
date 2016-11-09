#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

int w, h, k;
int dist[1<<14], match[1<<14];
vector<int> adj[1<<14], vert;
unordered_map<int, int> dead;

int co(int x, int y) { return (x<<7)|y; }
int cox(int co) { return co>>7; }
int coy(int co) { return co&0x3F; }

int dd(int x, int y) { if (dead.find(co(x, y)) != dead.end()) return 1; return 0; }

int bfs () {
    queue<int> Q;
    for (auto u:vert) {
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
            for (auto v:adj[u]) {
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
        for (auto v:adj[u]) {
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
        for (auto u:vert) {
            if (match[u] == 0) {
                if (dfs(u)) size++;
            }
        }
    }
    return size;
}

int main() {
    scanf("%d %d %d", &w, &h, &k);
    for (int i=0; i<k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dead[co(x, y)] = 1;
    }
    for (int x=0; x<w; x++) {
        for (int y=0; y<h; y++) {
            if (dd(x, y)) continue;
            vert.pb(co(x+1, y+1));
            if ((x+y)&1) {
                if (y<h-1 && !dd(x, y+1)) adj[co(x+1, y+1)].pb(co(x+1, y+2));
            } else {
                if (y>0 && !dd(x, y-1)) adj[co(x+1, y+1)].pb(co(x+1, y));
            }
            if (x>0 && !dd(x-1, y)) adj[co(x+1, y+1)].pb(co(x, y+1));
            if (x<w-1 && !dd(x+1, y)) adj[co(x+1, y+1)].pb(co(x+2, y+1));
        }
    }
    printf("%d\n", hopcroft_karp());
    return 0;
}
