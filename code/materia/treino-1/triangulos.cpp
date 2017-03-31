#include <cstdio>
#include <algorithm>
using namespace std;

int n, c, t;
long long d[100001], l;

int main(){
  d[0] = 0;
  while(scanf("%d", &n) != EOF){
    for(int i=1; i<=n; i++){
      scanf("%d", &t);
      d[i] = d[i-1] + t;
    }   
    if(d[n]%3){
      printf("0\n");
    }else{
      l = d[n]/3; c=0;
      for(int i=0; d[i]<l; i++){
        if(binary_search(d, d+n+1, d[i]+l) &&
            binary_search(d, d+n+1, d[i]+2*l))
          c++;
      }   
      printf("%d\n", c); 
    }   
  }
  return 0;
}