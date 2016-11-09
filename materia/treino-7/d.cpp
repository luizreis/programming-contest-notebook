#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define N 101

int main(){
  int tc = 1;

  int n, m;
  while(scanf("%d %d", &n, &m) && n){
    vector <pair <int, int> > adj[N];

    for(int i=0; i<m; i++){
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      adj[x].pb(mp(y, -z));
      adj[y].pb(mp(x, -z));
    }

    char vis[N];
    memset(vis, 0, sizeof(vis));

    priority_queue <pair<int, pair<int, int> > > Q;
    for(int i=0; i<adj[1].size(); i++)
      Q.push(mp(adj[1][i].second, mp(1, adj[1][i].first)));

    set <pair <int, int> > res;
    while(!Q.empty()){
      int p = Q.top().second.first, u = Q.top().second.second;
      Q.pop();

      if(vis[u]) continue;
      vis[u] = -1;
      res.insert(mp(min(p, u), max(p, u)));

      for(int i=0; i<adj[u].size(); i++)
        Q.push(mp(adj[u][i].second, mp(u, adj[u][i].first)));
    }

    printf("Teste %d\n", tc++);
    for(auto p: res)
      printf("%d %d\n", p.first, p.second);
    printf("\n");
  }

  return 0;
}
