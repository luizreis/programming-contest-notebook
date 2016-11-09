#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector <pair <int, int> > adj[1001];
int moeda[1001];
int nm;
int vis[(((1<<k)-1)<<1)+1][1001];

vector <pair <long long, int> > red[1001];

long long dij(){
    priority_queue <pair<>, vector <>, greater <> > Q;
    memset(vis, 0, sizeof vis);
    Q.push(make_pair(make_pair(0, 0), 1));
    while(!Q.empty()){
        long long d = Q.top().first.first;
        int vol = Q.top().first.second;
        int u = Q.top().second;
        Q.pop();

        if(u==1) vol++;
    //        printf("dist %lld vol %d, bm %x(%x), u %d\n", d, vol, bm,(((1<<k)-1)<<1) , u);
        if(vol == 4 && u == 1 && bm == ((1<<k)-1)<<1) return d;
        if(vol == 4) continue;

        if(vis[vol][bm][u]) continue;
        vis[vol][bm][u] = 1;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].second;
            int w = adj[u][i].first;
            int bt = bm;
            if(moeda[v]) bt |= (1<<moeda[v]);
            Q.push(make_pair(make_pair(d+w, vol), make_pair(bt, v)));
        }
    }

    return -1;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(c, b));
    }
    memset(moeda, 0, sizeof moeda);
    nm=1;
    for(int i=0; i<k; i++){
        int a;
        scanf("%d", &a);
        moeda[a]=nm++;
    }

    long long a = dij();
    if(a < 0) printf("impossivel\n");
    else printf("%lld\n", a);

    return 0;
}
