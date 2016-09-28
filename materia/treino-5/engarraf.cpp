#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > G[101];
int n, m, dist[101], i, j, k, t, s, d;

void dij(int s, int t) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;
    Q.push(make_pair(0, s));
    while (!Q.empty()) {
        int u = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if (dist[u] != -1) continue;
        dist[u] = d;
        if (u == t) break;
        for (int i = 0; i < G[u].size(); i++) {
            Q.push(make_pair(d + G[u][i].second, G[u][i].first));
        }
    }
}


int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        memset(dist, -1, sizeof(dist));
        for (int k = 0; k <= n; k++) G[k].clear();
        for (int k = 0; k < m; k++) {
            scanf("%d %d %d", &i, &j, &t);
            G[i].push_back(make_pair(j, t));
        }
        scanf("%d %d", &s, &d);
        dij(s, d);
        printf("%d\n", dist[d]);
    }
    return 0;
}
