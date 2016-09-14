#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
#define MAX 30

using namespace std;

int w, h, g, e;
int dist[MAX][MAX], r[MAX][MAX], vis[MAX][MAX][MAX][MAX];
vector< pair< pair<int, int> , int> > adj[MAX][MAX];

int bellman_ford(int x, int y, int dx, int dy) {
    int vc = w*h;
    
    memset(dist, 0x3f, sizeof(dist));   
    dist[x][y] = 0;
    
    for (int a = 1; a < vc; a++) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (i == dx && j == dy) continue;
                for (int k = 0; k < adj[i][j].size(); k++) {
                    if (dist[i][j] != INF && dist[i][j] + adj[i][j][k].second < dist[adj[i][j][k].first.first][adj[i][j][k].first.second]) {
                        dist[adj[i][j][k].first.first][adj[i][j][k].first.second] = dist[i][j] + adj[i][j][k].second;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (i == dx && j == dy) continue;
            for (int k = 0; k < adj[i][j].size(); k++) {
                if (dist[i][j] != INF && dist[i][j] + adj[i][j][k].second < dist[adj[i][j][k].first.first][adj[i][j][k].first.second]) {
                    return -1;
                }
            }
        }
    }
}

int main() {
    int x, y, _x, _y, t, ans;
    scanf("%d %d", &w, &h);
    while (w && h) {
        memset(r, 0, sizeof(r));
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adj[i][j].clear();
            }
        }
        
        scanf("%d", &g);
        for (int i = 0; i < g; i++) {
            scanf("%d %d", &x, &y);
            r[x][y] = 1;
        }
        
        scanf("%d", &e);
        for (int i = 0; i < e; i++) {
            scanf("%d %d %d %d %d", &x, &y, &_x, &_y, &t);
            adj[x][y].push_back(make_pair(make_pair(_x, _y), t));
            r[x][y] = 1;
        }
        
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (!r[i][j]) {
                    if (i > 0) adj[i][j].push_back(make_pair(make_pair(i - 1, j), 1));
                    if (i < w - 1) adj[i][j].push_back(make_pair(make_pair(i + 1, j), 1));
                    if (j > 0) adj[i][j].push_back(make_pair(make_pair(i, j - 1), 1));
                    if (j < h - 1) adj[i][j].push_back(make_pair(make_pair(i, j + 1), 1));
                }
            }
        }
        
        ans = bellman_ford(0, 0, w-1, h-1);
        
        if (ans == -1) printf("Never\n");
        else if (dist[w-1][h-1] == INF) printf("Impossible\n");
        else printf("%d\n", dist[w-1][h-1]);
        
        scanf("%d %d", &w, &h);
    }
    return 0;
}