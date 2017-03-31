#include <cstdio>

using namespace std;

#define MAX(a, b) (a>b)?(a):(b)

int main () {
  int n, c;
  int vec[200001];
  scanf("%d %d", &n, &c);
  for ( int i = 0; i < n; i++)
    scanf("%d", &vec[i]);

  int max0=0, max1=0;

  for ( int i=n-1; i >=0; i--){
    max0 = MAX(max0, max1-vec[i]-c);
    max1 = MAX(max1, max0+vec[i]);
  }

  printf("%d\n", max0);
  return 0;
}

