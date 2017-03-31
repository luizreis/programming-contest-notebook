#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX(a,b) ((a)>(b))?(a):(b)

int n, q, temp1, temp2, temp3, aux;
vector< pair<int, int> > adj[100001];
int L[100001], P[100001][17], H[100001][17], T[100001];

void processanc () {
  for (int i=0; i< n; i++)
    for(int j=0;1<<j < n; j++)
      P[i][j] = -1;

  for (int i=0; i<n;i++)
    P[i][0] = T[i];

  for (int j =1; 1<<j < n; j++)
    for (int i=0;i<n;i++)
      if(P[i][j -1] != -1) {
        H[i][j] = MAX(H[i][j - 1], H[P[i][j - 1]][j-1]);
        P[i][j] = P[P[i][j-1]][j-1];
      }
}

int lca(int p, int q) {
  int tmp, log, i, t = 0;

  if(L[p] < L[q])
    tmp = p, p =q, q=tmp;

  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  for(i=log; i >=0; i--)
    if(L[p] - (1<<i) >= L[q]) {
      if (t < H[p][i]) t = H[p][i];
      p = P[p][i];
    }

  if (p == q)
    return t;

  for (i=log; i>= 0; i--)
    if(P[p][i] != -1 && P[p][i] != P[q][i]) {
      if (t < H[p][i]) t = H[p][i];
      if (t < H[q][i]) t = H[q][i];
      p = P[p][i], q = P[q][i];
    }

  if (t < H[p][0]) t = H[p][0];
  if (t < H[q][0]) t = H[q][0];
  return t;
}

bool vis[100001];

void root (int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (int i=0; i < adj[v].size(); i++) {
    if (vis[adj[v][i].first]) continue;
    L[adj[v][i].first] = L[v]+1;
    T[adj[v][i].first] = v;
    H[adj[v][i].first][0] = adj[v][i].second;
    root (adj[v][i].first);
  }
}

int main () {
  start:
  scanf("%d", &n);
  memset(vis, false, sizeof(vis));
  for (int i =0; i <= n; i++) adj[i].clear();
  if (n == 0) return 0;
  for (int i=1; i < n; i++) {
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    temp1--;
    temp2--;
    adj[temp2].push_back(pair<int, int> (temp1, temp3));
    adj[temp1].push_back(pair<int, int> (temp2, temp3));
  }
  
  L[0] = 0;
  T[0] = -1;
  H[0][0] = 0;;

  root(0);

  processanc();

  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    scanf("%d %d", &temp1, &temp2);
    printf("%d\n", lca(--temp1, --temp2));
  }
  goto start;

  return 0;
}

