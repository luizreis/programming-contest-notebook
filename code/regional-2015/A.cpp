#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

vector <pair<int, int> > adj[10000+1];
int c, v, dist[10000+1];
int ncid=1, vped=0;
int pes[10001][2];

void dij(){
  memset(pes, -1, sizeof(pes));

  priority_queue <pair <int, pair <int, int> >, vector < pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > fila;
  fila.push(make_pair(0, make_pair(1, 0)));

  while(!fila.empty()){
    int u = fila.top().second.first;
    int paru = fila.top().second.second;
    pes[u][paru] = fila.top().first;

    if(u == c && !paru)
      break;

    fila.pop();

    for(int i = 0; i < adj[u].size(); i++){
      int w = adj[u][i].first, pesw = adj[u][i].second;
      if(pes[w][(paru+1)&1] < 0)
        fila.push(make_pair(pes[u][paru]+pesw,make_pair(w, (paru+1)&1)));
    }
  }

  if(fila.empty())
    printf("-1\n");
  else
    printf("%d\n", fila.top().first);
}

int main () {
  int t1, t2,t3;
  pair <int, int> x;
  scanf("%d %d", &c, &v);
  for (int i=0; i<v; i++){
    scanf("%d %d %d", &t1, &t2, &t3);
    x.first = t2;
    x.second = t3;
    adj[t1].push_back(x);
    x.first = t1;
    x.second = t3;
    adj[t2].push_back(x);
  }

  dij();

  return 0;

}
