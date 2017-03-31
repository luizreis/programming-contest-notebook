#include <bits/stdc++.h>
using namespace std;

int n, f;
vector <int> adj[100010], pes[100010];
int tem[100010], cus[100010];
int mai = 0;

void dfs(int v, int acc){
    if(tem[v] && acc > mai){
        mai = acc;
    }

    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        dfs(u, acc+pes[v][i]);
        if(tem[u]){
            tem[v] = -1;
            cus[v] += pes[v][i] + cus[u];
        }
    }

    return;
}

int main(){
    while(scanf("%d %d", &n, &f) != EOF){
        for(int i=1; i<=n; i++) adj[i].clear(), pes[i].clear();
        memset(cus, 0, sizeof(cus));
        memset(tem, 0, sizeof(tem));

        for(int i=1; i<n; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(b);
            pes[a].push_back(c);
        }

        for(int i=0; i<f; i++){
            int t;
            scanf("%d", &t);
            tem[t] = -1;
        }

        mai = 0;
        dfs(1, 0);
        printf("%d\n", cus[1]-mai);
    }

    return 0;
}
