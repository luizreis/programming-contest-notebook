#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int n, m, a, b, x, y, s;
int g[100010], vis[100010];
vector<int> adj[100010];
set<pair<int, int> > v;

int main() {
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        g[x]++; g[y]++;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    s = n;
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) v.insert(mp(g[i], i));
    while (!v.empty()) {
        int w, gw;
        if ((v.begin())->first < a) {
            w = (v.begin())->second;
            gw = (v.begin())->first;
        } else if (s-1-(v.rbegin())->first < b) {
            w = (v.rbegin())->second;
            gw = (v.rbegin())->first;
        } else {
            break;
        }
        v.erase(mp(gw, w));
        vis[w] = 1;
        for (auto u: adj[w]) {
            if (vis[u]) continue;
            v.erase(mp(g[u]--, u));
            v.insert(mp(g[u], u));
        }
        s--;
    }
    printf("%d\n", s);
    return 0;
}
