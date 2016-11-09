#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

const ll INF = 1e14;

struct edge {
    int u, v;
    ll cap, flow, cost;
    ll rem() { return cap - flow; }
};

int n, m, d, k, pre[102], u[5001], v[5001], c[5001];
vector<int> adj[102];
vector<edge> e;
ll dist[102], cap[102], min_cost, max_flow;
bool in_queue[102];

void add_edge(int u, int v, ll cap, ll cost) {
    adj[u].pb(e.size()); e.pb((edge){u, v, cap, 0, cost});
    adj[v].pb(e.size()); e.pb((edge){v, u, 0, 0, -cost});
}

void flow(int s, int t) {
    memset(in_queue, 0, sizeof (in_queue));
    min_cost = max_flow = 0;
    while (1) {
        for (int i=0; i<n; i++) dist[i] = INF; dist[s] = 0;
        memset(pre, -1, sizeof(pre)); pre[s] = 0;
        memset(cap, 0, sizeof(cap)); cap[s] = INF;
        queue<int> q; q.push(s); in_queue[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop(); in_queue[u] = 0;
            for (auto it:adj[u]) {
                edge &E = e[it];
                if (E.rem() && dist[E.v] > dist[u] + E.cost) {
                    dist[E.v] = dist[u] + E.cost;
                    pre[E.v] = it;
                    cap[E.v] = min(cap[u], E.rem());
                    if (!in_queue[E.v]) q.push(E.v), in_queue[E.v] = 1;
                }
            }
        }
        if (pre[t] == -1) break;
        max_flow += cap[t];
        min_cost += cap[t]*dist[t];
        for (int v = t; v != s; v = e[pre[v]].u) {
            e[pre[v]].flow += cap[t];
            e[pre[v]^1].flow -= cap[t];
        }
    }
}


int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i=0; i<=n; i++) adj[i].clear();
        e.clear();
        for (int i=0; i<m; i++) scanf("%d %d %d", u+i, v+i, c+i);
        scanf("%d %d", &d, &k);
        n++;
        add_edge(0, 1, d, 0);
        for (int i=0; i<m; i++) {
            add_edge(u[i], v[i], k, c[i]);
            add_edge(v[i], u[i], k, c[i]);
        }
        flow(0, n-1);
        if (max_flow == d) printf("%lld\n", min_cost);
        else printf("Impossible.\n");
    }
    return 0;
}
