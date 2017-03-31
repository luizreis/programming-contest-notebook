#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int N = 1001;

vector<pair<int, int> > adj[N];
char vis[N];

long long mst(int r) {
    long long tot = 0;
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, pair<int, int> > > q;
    for (auto u:adj[r]) {
        q.push(mp(u.second, mp(r, u.first)));
    }
    vis[r] = 1;
    while (!q.empty()) {
        int v = q.top().second.second;
        int p = q.top().second.first;
        int d = q.top().first;
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        tot += -d;
        for (auto u:adj[v]) {
            q.push(mp(u.second, mp(v, u.first)));
        }
    }
    return tot;
}

void addedge(int x, int y, int d) {
    adj[x].pb(mp(y, -d));
    adj[y].pb(mp(x, -d));
}

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addedge(a, b, c);
    }
    long long tot = 0;
    tot = mst(1);
    bool cov = true;
    for (int i=1; i<=n; i++) if (!vis[i]) cov = false;
    if (cov) printf("%lld\n", tot);
    else printf("impossivel\n");
    return 0;
}
