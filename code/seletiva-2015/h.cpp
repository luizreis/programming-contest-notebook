#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define PAREDE 12
#define ROBO 10
#define PISO 10
#define SAIDA 11
#define VISITADO 1

typedef struct {
  int x, y, p, m;
} estado;

int poeiras = 0, mapa[100][100];
char estados[100][100][256];
queue<estado> Q;

int main (){
  int n, m, w, h, poeira = 0, x, y, soma, saida = 0;
  char temp;
  scanf("%d %d %d %d\n", &n, &m, &w, &h);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%c", &temp);
      switch (temp) {
        case '.' : mapa[i][j] = PISO; break;
        case '#' : mapa[i][j] = PAREDE; break;
        case 'R' : mapa[i][j] = ROBO; x = j; y = i; break;
        case 'S' : mapa[i][j] = SAIDA; break;
        case '*' : mapa[i][j] = poeira++; break;
        default : break;
      }
    } scanf("%*c");
  }

  memset(estados, 0, sizeof(estados));

  estado ea;
  Q.push((estado){x, y, 0, 0});
  while (!Q.empty()) {
    ea = Q.front();
    Q.pop();
    
    if (ea.x >= w || ea.x < 0 || ea.y >= h || ea.y < 0 || ea.m > m) continue;
    if (estados[ea.y][ea.x][ea.p] == VISITADO) continue;
    estados[ea.y][ea.x][ea.p] = VISITADO;
    if (mapa[ea.y][ea.x] == PISO) {
      piso:
      Q.push((estado){ea.x+1, ea.y, ea.p, ea.m+1});
      Q.push((estado){ea.x-1, ea.y, ea.p, ea.m+1});
      Q.push((estado){ea.x, ea.y+1, ea.p, ea.m+1});
      Q.push((estado){ea.x, ea.y-1, ea.p, ea.m+1});
      continue;
    }
    if (mapa[ea.y][ea.x] < 8) {
      ea.p |= 1 << mapa[ea.y][ea.x];
      goto piso;
    }
    if (mapa[ea.y][ea.x] == SAIDA) {
      soma = 0;
      saida = 1;
      soma += (ea.p & 1 << 0) ? 1 : 0;
      soma += (ea.p & 1 << 1) ? 1 : 0;
      soma += (ea.p & 1 << 2) ? 1 : 0;
      soma += (ea.p & 1 << 3) ? 1 : 0;
      soma += (ea.p & 1 << 4) ? 1 : 0;
      soma += (ea.p & 1 << 5) ? 1 : 0;
      soma += (ea.p & 1 << 6) ? 1 : 0;
      soma += (ea.p & 1 << 7) ? 1 : 0;
      if (soma > poeiras) poeiras = soma;
    }
  }

  printf("%d\n", (saida)? poeiras : -1);
    
  /*for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%d", mapa[i][j]);
    } printf("\n");
  }*/

  return 0;
}

