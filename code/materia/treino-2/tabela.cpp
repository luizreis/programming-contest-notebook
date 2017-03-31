#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> vec[1000];
int vis[1000];


int dfs(int i, int c){
  vis[i] = c;
  c = (c+1)%2;

  for (int j =0; j < vec[i].size(); j++){
    if(vis[vec[i][j]] == -1){
      if(!dfs(vec[i][j], c)) return 0;
    }else if(vis[vec[i][j]] != c)
      return 0;
  }
  return 1;
}

int main(){
  int n,m,u,v,k;
  k = 0;

ler:
  if(scanf("%d %d", &n, &m) == EOF) return 0;
  k++;
  memset(vis, -1, sizeof(vis));
  for (int i =0 ; i < 1000; i++)
    vec[i].clear();

  for (int i = 1; i <= m; i++){
    scanf("%d %d", &u,&v);
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  printf("Instancia %d\n",k);
  for (int i =1; i <= n; i++){
    if(vis[i] == -1)
      if(!dfs(i,0)){
        printf("nao\n\n");
        goto ler;
      }
  }
  printf("sim\n\n");
  goto ler;
  return 0;
}