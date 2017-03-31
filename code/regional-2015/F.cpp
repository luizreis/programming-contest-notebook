#include <cstdio>
#define min(a,b) (a < b) ? (a) : (b)

using namespace std;
int n, m;
int vec[] = {1, 2, 6, 24, 120, 720, 5040, 40320};

int main(){

  scanf("%d", &n);

  m = 0;
  for(int i=7; n!=0; i--){
    if(n-vec[i] >= 0){
      n-=vec[i];
      i++, m++;
    }
  }

  printf("%d\n", m);

  return 0;
}
