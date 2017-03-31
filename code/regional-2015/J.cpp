#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int vec[500];

  int n,r,temp;
  scanf("%d %d",&n,&r);
  memset(vec,0,sizeof(vec));
  for(int i=0;i < n*r; i++){
    scanf("%d",&temp);
    vec[i%n] += temp;
  }
  int max=0, maxi=0;
  for(int i=0; i<n; i++){
    if (max <= vec[i]){
      max = vec[i];
      maxi= i;
    }
  }
  printf("%d\n",maxi+1);
  return 0;
}


