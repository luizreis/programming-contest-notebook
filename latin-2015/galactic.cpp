#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, pair<int, int> > piii;
typedef pair<double, int> pdi;

int n, m;
vector<piii> adj[1010];
bool vis[1010];

double dij(double t) {
    memset(vis, 0 ,sizeof(vis));
    priority_queue<pdi, vector<pdi>, greater<pdi> > q;
    q.push(mp(0.0, 1));
    while(!q.empty()) {
        double d = q.top().first;
        int v = q.top().second;
        q.pop();
        if (v == n) return d;
        if (vis[v]) continue;
        vis[v] = 1;
        for (int i=0; i<adj[v].size(); i++)
            q.push(mp(d + adj[v][i].second.first*t + adj[v][i].second.second, adj[v][i].first));
    }
    return -1.0;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i=0; i<1010; i++) adj[i].clear();
        for (int i=0; i<m; i++) {
            int x, y, a, b;
            scanf("%d %d %d %d", &x, &y, &a, &b);
            adj[x].pb(mp(y, mp(a, b)));
            adj[y].pb(mp(x, mp(a, b)));
        }
        double a = 0, b = 24*60, m1, m2;
        for (int i = 0; i < 100; i++) {
            m1 = (a+((b-a)/3));
            m2 = (b-((b-a)/3));
            if (dij(m1) > dij(m2)) b = m2;
            else a = m1;
        }
        printf("%.5lf\n", dij((a+b)/2));
    }
    return 0;
}
