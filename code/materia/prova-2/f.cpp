#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

const int MAXN = 1005;
const int MAXK = 12;
const int INF = 0x3f3f3f3f;

int n, m, k, coin[MAXN];
vector<pii> adj[MAXN], g[MAXK+1];
bool vis[MAXN];
int mem[4][(((1<<MAXK)-1)<<1)+10][MAXK+1];

void dij(int r) {
    int addz = 1;
    memset(vis, 0, sizeof(vis));
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;
    Q.push(make_pair(0, r));
    while(!Q.empty()) {
        int d = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (v == 0 && v == r && addz && d > 0) {
            g[coin[r]].push_back(make_pair(v, d));
            addz = 0;
        }
        if (vis[v]) continue;
        vis[v] = 1;
        //printf("dij for %d: coin is %d and v is %d | dist is %d\n", r, coin[v], v, d);
        if (coin[v] && v != r) g[coin[r]].push_back(make_pair(coin[v], d));
        if (v == 0 && v != r) {
            g[coin[r]].push_back(make_pair(v, d));
            continue;
        }
        for (int i = 0; i < adj[v].size(); i++)
            Q.push(make_pair(d + adj[v][i].second, adj[v][i].first));
    }
}

int pd() {
    priority_queue <pair<pair<long long, int>, pair<int, int> >, vector <pair<pair<long long, int>, pair<int, int> > >, greater < pair<pair<long long, int>, pair<int, int> > > > Q;
    memset(mem, 0, sizeof mem);
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    while(!Q.empty()){
        long long d = Q.top().first.first;
        int vol = Q.top().first.second;
        int bm = Q.top().second.first;
        int u = Q.top().second.second;
        Q.pop();

        if(u==0) vol++;
        //printf("dist %lld vol %d, bm %x(%x), u %d\n", d, vol, bm,(((1<<k)-1)<<1) , u);
        if(vol == 4 && u == 0 && bm == ((1<<k)-1)<<1) return d;
        if(vol == 4) continue;

        if(mem[vol][bm][u]) continue;
        mem[vol][bm][u] = 1;

        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            int bt = bm;
            if(v) bt |= (1<<v);
            Q.push(make_pair(make_pair(d+w, vol), make_pair(bt, v)));
        }
    }

    return -1;
}

int main() {
    memset(coin, 0, sizeof(coin));
    int a, b, t;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        a--, b--;
        adj[a].push_back(make_pair(b, t));
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &t);
        coin[--t] = i;
    }
    dij(0);
    for (int i = 1; i < n; i++) {
        if(coin[i]) dij(i);
    }
    /*for (int i = 0; i <= k; i++) {
        printf("%d adj list: ", i);
        for (int j = 0; j < g[i].size(); j++) {
            printf("%d(%d) ", g[i][j].first, g[i][j].second);
        }
        printf("\n");
    }*/
    long long ans = pd();
    if (ans == -1) printf("impossivel\n");
    else printf("%lld\n", ans);
    return 0;
}
