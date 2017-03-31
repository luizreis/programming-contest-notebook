#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int> > adj[2][101];
int n, m, a, b, t, r;
int vis[101];

long long dij(int t) {
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > Q;
    memset(vis, 0, sizeof(vis));
    Q.push(make_pair(0, 1));
    while(!Q.empty()) {
        long long d = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (vis[v]) continue;
        if (v == n) return d;
        vis[v] = 1;
        for (int i = 0; i < adj[t][v].size(); i++) {
            Q.push(make_pair(d + adj[t][v][i].first, adj[t][v][i].second));
        }
    }
    return 10000000;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &t, &r);
        adj[t][a].push_back(make_pair(r, b));
    }
    printf("%lld\n", min(dij(0), dij(1)));
    return 0;
}
