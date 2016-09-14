#include <cstdio>
#include <cstdlib>

using namespace std;

int dias[1001];

int comp(const void *p1, const void *p2){
  return (*(int *)p1 - *(int *)p2);
}

int main(){
  int n;
  long long int soma = 0;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &dias[i]);
  }

  qsort(dias, n, sizeof(int), comp);

  for (int i =0; i < n/2; i++){
    int somar = dias[n-i-1] - dias[i];
    soma += somar;
  }

  printf("%lld\n", soma);

  return 0;
}
