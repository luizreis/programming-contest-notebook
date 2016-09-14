#include <cstdio>
#include <cstring>

using namespace std;

int vec[1000];
int mem[1000][1000];
int n, m;

int pd (int pac, int bala) {
  if (pac == m) {
    if (bala == 0) return 0;
    else return -10000;
  }
  if (mem[pac][bala] != -1) return mem[pac][bala];
  int opc1, opc2;
  opc1 = 1 + pd(pac+1, (bala + vec[pac])%n);
  opc2 = pd(pac+1, bala);
  //mem[pac][bala] = ((opc1 > opc2)? (opc1 != 0)?opc1:(opc2) : (opc2 != -1 ) ? opc2 : (opc1 == 0)? -1 : 0);
  mem[pac][bala] = (opc1 > opc2)?opc1:opc2;
  return (opc1 > opc2)?opc1:opc2;
}

int main () {
  memset(mem, -1, sizeof(mem));

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++)
    scanf("%d", &vec[i]);

  printf("%d\n", pd(0, 0));
  return 0;
}
