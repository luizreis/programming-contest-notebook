#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, n;
char in[101];

int mem[101][101][10];

int valor(char c_) {
    switch (c_) {
        case 'a': return a; break;
        case 'b': return b; break;
        case 'c': return c; break;
    }
}

int pd(int v, int u, int bonus) {
    if (v >= n) return 0;
    if (mem[v][u][bonus] != -1) return mem[v][u][bonus];
    int opc1 = pd(v+1, u, bonus);
    int bon = (in[u] == in [v])?min(bonus+1, 10):1;
    int opc2 = pd(v+1, v, bon) + valor(in[v])*(1<<(bon-1));
    mem[v][u][bonus] = max(opc1, opc2);
    return mem[v][u][bonus];
}

int main () {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        scanf("%s", in);
        n = strlen(in);
        memset(mem, -1, sizeof(mem));
        printf("%d\n", pd(1, 0, 1)+valor(in[0]));
    }
    return 0;
}
