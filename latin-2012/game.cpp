#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

char mapa[51][51];
int r, c;
int dist[1<<12], match[1<<12], vis[1<<12];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<int> vert;

int co(int x, int y) { return x<<6 | (y+1); }
int cox(int co) { return co>>6; }
int coy(int co) { return (co&0x3F)-1; }

int conta(int u) {
    int res = 0;
	queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        int x = cox(v), y = coy(v);
        if (mapa[x][y] == '.') res++, vert.pb(v);
        for (int i=0; i<4; i++) {
            if (x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c) {
                q.push(co(x+dx[i], y+dy[i]));
            }
        }
    }
    return res;
}

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
            int x = cox(u), y = coy(u);
            for (int i=0; i<4; i++)
            if (x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c && mapa[x+dx[i]][y+dy[i]] == '.') {
                int v = co(x+dx[i], y+dy[i]);
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
        int x = cox(u), y = coy(u);
        for (int i=0; i<4; i++)
        if (x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c && mapa[x+dx[i]][y+dy[i]] == '.') {
            int v = co(x+dx[i], y+dy[i]);
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

int hopcroft_karp(int x, int y) {
    int size = 0;
    vert.clear();
    int tot = conta(co(x, y));
    //printf("HK for (%d, %d)(%d)\nVert: ", x, y, co(c, y));
    //for (auto v:vert) printf("%d(%d, %d) ", v, cox(v), coy(v));
    //printf("\n");
    while (bfs()) {
        for (auto u:vert) {
            if (match[u] == 0) {
                if (dfs(u)) size++;
            }
        }
    }
    //for (auto v:vert) printf("%d - %d\n", v, match[v]);
    //printf("size %d | tot %d\n", size, tot);
    return size*2 == tot;
}

int main() {
    while (scanf("%d %d", &r, &c) != EOF) {
        int p2 = 1;
        memset(match, 0, sizeof(match));
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<r; i++) scanf("%s", mapa[i]);
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if (mapa[i][j] == '.' && !vis[co(i, j)] && !hopcroft_karp(i, j)) p2 = 0;
        printf("%d\n", (p2)?2:1);
    }
    return 0;
}
