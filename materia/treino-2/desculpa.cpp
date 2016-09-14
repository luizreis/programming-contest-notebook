#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int c, f, n, d;
int vec[2][50];
int mem[10001][51];

int pd( int i, int cap) {
  if (i >= f) return 0;
  if (cap < 0) return 0;
  if (mem[cap][i] != -1) return mem[cap][i];
  int opc1 = pd(i+1, cap);
  int opc2 = 0;
  if (cap - vec[0][i] >= 0)
    opc2 = vec[1][i] + pd(i+1, cap - vec[0][i]);
  mem[cap][i] = max(opc1, opc2);
  return mem[cap][i];
}

int main () {
  int t = 1;
  while (1) {
    scanf("%d %d", &c, &f);
    memset(mem, -1, sizeof(mem));
    if (!c && !f) return 0;
    for (int i = 0; i < f; i++) {
      scanf("%d %d", &n, &d);
      vec[0][i] = n;
      vec[1][i] = d;
    }   
    printf("Teste %d\n%d\n\n", t, pd(0, c));
    t++;
  }
  return 0;
}
