#include <cstdio>
#include <cstring>

#define MIN(a, b) (((a)<(b))?(a):(b))
int N, M;
char L;
int S[400][2];

int main () {
  while (scanf("%d", &N) != EOF) {
    memset(S, 0, sizeof(S));
    for (int i = 0; i < N; i++) {
      scanf("%d %c", &M, &L);
      if (L == 'E') S[M][0]++;
      else S[M][1]++;
    }   
    int C = 0;
    for (int i = 30; i <= 60; i++) {
      C += MIN(S[i][0], S[i][1]);
    }   
    printf("%d\n", C); 
  }
  return 0;
}
