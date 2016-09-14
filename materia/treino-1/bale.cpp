#include <cstdio>
#include <cstring>

int tree[100010];
int maxval=100001;

int n, np, v[100010];

int read(int idx){
  int sum=0;
  while(idx > 0){
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, int val){
  while(idx <= maxval){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

int main(){
  memset(tree, 0, sizeof(tree));

  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", v+i);

  np=0;
  for(int i=n; i>=1; i--){
    np += read(v[i]);
    update(v[i],1);
  }
  printf("%d\n", np);
  return 0;
}
