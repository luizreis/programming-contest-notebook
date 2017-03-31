#include <bits/stdc++.h>

using namespace std;

#define msz(a) (memset(a, 0, sizeof (a)))

int n, k;
int P[101], D[101];
int mem[101][100001];

int pd(int i, int p) {
    if (i >= n) return 0;
    if (mem[i][p] != -1) return mem[i][p];
    int opc1 = pd(i+1, p);
    int opc2 = 0;
    if (P[i] <= p) opc2 = pd(i+1, p - P[i]) + D[i];
    mem[i][p] = max(opc1, opc2);
    return mem[i][p];
}

int main () {
    scanf("%d %d", &n, &k);
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        D[i] = a;
    }
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        P[i] = a;
    }
    printf("%d\n", pd(0, k));
    return 0;
}
