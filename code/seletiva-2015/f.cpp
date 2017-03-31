#include <cstdio>
#include <string.h>

int MaxVal=1000001, tree[1000001];
long long int matriz[1000000][2];

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

using namespace std;


int main(){
  memset(tree, 0, sizeof(tree));

  int n, a;
  long long int counter = 0, val;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a);
    val = n - a + 1;
    matriz[i][0] = read(val);
    update(val, 1);
    matriz[i][1] = a;
  }

  memset(tree, 0, sizeof(tree));
  for (int i = 0; i < n; i++){
    val = n - i - 1;
    a = read(matriz[val][1]);
    counter += a * matriz[val][0];
    update(matriz[val][1], 1);
  }
    
  printf("%lld\n", counter);

  return 0;
}
