#include <cstdio>
#include <vector>

using namespace std;

long long int dist[100001];
int n, q, temp1, temp2;
vector<int> adj[100001];
int L[100001], P[100001][17], T[100001];

void dfs (int v) {
  for (int i = 0; i < adj[v].size(); i++) {
    //printf("dist(%lld) = %lld\n", v, dist[v]);
      dist[adj[v][i]] = dist[v] + dist[adj[v][i]];
      dfs(adj[v][i]);
  }
}

void processanc () {
  for (int i=0; i< n; i++)
    for(int j=0;1<<j < n; j++)
      P[i][j] = -1;

  for (int i=0; i<n;i++)
    P[i][0] = T[i];

  for (int j =1; 1<<j < n; j++)
    for (int i=0;i<n;i++)
      if(P[i][j -1] != -1)
        P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int p, int q) {
  int tmp, log, i;

  if(L[p] < L[q])
    tmp = p, p =q, q=tmp;

  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  for(i=log; i >=0; i--)
    if(L[p] - (1<<i) >= L[q])
      p = P[p][i];

  if (p == q)
    return p;

  for (i=log; i>= 0; i--)
    if(P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];

  return T[p];
}

long long int calcdist (int a, int b){
  return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}

int main () {
  start:
  dist[0] = 0;
  L[0] = 0;
  T[0] = -1;
  scanf("%d", &n);
  for (int i =0; i < n; i++) adj[i].clear();
  if (n == 0) return 0;
  for (int i=1; i < n; i++) {
    scanf("%d %d", &temp1, &temp2);
    adj[temp1].push_back(i);
    dist[i] = temp2;
    // prepara pre processamento da lca
    T[i] = temp1;
    L[i] = L[temp1]+1;
  }

  processanc();
  dfs(0);

  /*for ( long long int i =0; i < n; i++)
    printf("%lld\n", dist[i]);*/

  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    scanf("%d %d", &temp1, &temp2);
      if (i) printf(" ");
    printf("%lld", calcdist(temp1, temp2));
  }
  printf("\n");
  goto start;

  return 0;
}
