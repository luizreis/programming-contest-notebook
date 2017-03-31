#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

#define MAX(a,b) ((a)>(b))?(a):(b)

int n, q, k, temp1, temp2, temp3, aux;
vector< pair<int, int> > adj[100001];
long long int count = 0;
int L[100001], P[100001][17], T[100001];
vector<int> H[100001][17];
vector<int>::iterator h1, h2;

vector<int> mergeVec (vector<int> v1, vector<int> v2) {
  vector<int> r;
  int j=0, k = 0;
  for (int i = 0; i < 5; i++){
    if (j == v1.size() && k == v2.size()) break;
    else if (j == v1.size()) goto sobek;
    else if (k == v2.size()) goto sobej;
    else if (v1[j] < v2[k]) {
      sobek:
      r.push_back(v2[k]);
      k++;
    } else {
      sobej:
      r.push_back(v1[j]);
      j++;
    }
  }
  return r;
}


void processanc () {
  for (int i=0; i< n; i++)
    for(int j=0;1<<j < n; j++)
      P[i][j] = -1;

  for (int i=0; i<n;i++)
    P[i][0] = T[i];

  for (int j =1; 1<<j < n; j++)
    for (int i=0;i<n;i++)
      if(P[i][j -1] != -1) {
        //H[i][j] = MAX(H[i][j - 1], H[P[i][j - 1]][j-1]);
        H[i][j] = mergeVec(H[i][j - 1], H[P[i][j - 1]][j-1]);
        P[i][j] = P[P[i][j-1]][j-1];
      }
}

void lca(int p, int q) {
  int tmp, log, i;
  vector<int> t;

  if(L[p] < L[q])
    tmp = p, p =q, q=tmp;

  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  for(i=log; i >=0; i--)
    if(L[p] - (1<<i) >= L[q]) {
      //if (t < H[p][i]) t = H[p][i];
      t = mergeVec(H[p][i], t);
      p = P[p][i];
    }

  if (p == q)
    goto imprime;

  for (i=log; i>= 0; i--)
    if(P[p][i] != -1 && P[p][i] != P[q][i]) {
      //if (t < H[p][i]) t = H[p][i];
      //if (t < H[q][i]) t = H[q][i];
      t = mergeVec(H[p][i], t);
      t = mergeVec(H[q][i], t);
      p = P[p][i], q = P[q][i];
    }

  //if (t < H[p][0]) t = H[p][0];
  //if (t < H[q][0]) t = H[q][0];
  t = mergeVec(H[p][0], t);
  t = mergeVec(H[q][0], t);

  imprime:
  for (i = 0; i < t.size() && i < k; i++) {
    if (i) printf(" ");
    printf("%d", t[i]);
  }
  printf("\n");
  return ;
}

bool vis[100001];

void root (int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (int i=0; i < adj[v].size(); i++) {
    if (vis[adj[v][i].first]) continue;
    L[adj[v][i].first] = L[v]+1;
    T[adj[v][i].first] = v;
    H[adj[v][i].first][0].push_back(adj[v][i].second);
    root (adj[v][i].first);
  }
}

int main () {
  scanf("%d", &n);
  memset(vis, false, sizeof(vis));
  pair<int, int> temp;
  for (int i=1; i < n; i++) {
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    temp1--;
    temp2--;
    temp.first = temp1;
    temp.second = temp3;
    adj[temp2].push_back(temp);
    temp.first = temp2;
    temp.second = temp3;
    adj[temp1].push_back(temp);
  }
  
  L[0] = 0;
  T[0] = -1;
  H[0][0].push_back(0);

  root(0);
  processanc();

  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    scanf("%d %d %d", &temp1, &temp2, &k);
    lca(--temp1, --temp2);
  }

  return 0;
}
