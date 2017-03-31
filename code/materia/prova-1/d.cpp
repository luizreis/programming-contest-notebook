#include <bits/stdc++.h>

using namespace std;

#define msz(a) (memset(a, 0, sizeof (a)))

int vis[10001];
vector<int> adj[10001];

int dfs(int i){
    if(vis[i])
        return 0;
    vis[i] = 1;

    int ac=0;
    for(int j=0; j< adj[i].size(); j++){
        ac += dfs(adj[i][j]);
    }
    return ac+1;
}


int main () {
    int n,m,t,t2;
    scanf("%d %d", &n,&m);
    for (int i=0; i < m; i++){
        scanf("%d %d", &t,&t2);
        adj[t].push_back(t2);
        adj[t2].push_back(t);
    }
    msz(vis);
    scanf("%d", &t2);
    int minn  = 0x3f3f3f3f;
    printf("%d\n",dfs(t2));
    return 0;
}
