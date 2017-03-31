#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull m, tot = 0, mem[1010][1010];
int n, a = 0, f = 0;

ull pd(int a, int f) {
    int pos = a+f;
    if (pos >= n) return 1;
    ull &res = mem[a][f];
    if (res > 0) return res;
    ull opc1 = 0, opc2 = 0;
    if (a < n/2) opc1 = pd(a+1, f);
    if (f < a) opc2 = pd(a, f+1);
    res = min(opc1 + opc2, (ull)1e18);
    return res;
}

int main() {
    scanf("%d %llu", &n, &m);
    memset(mem, 0, sizeof(mem));
    pd(0, 0);
    for (int i=0; i<n; i++) {
        if (m <= tot+mem[a+1][f]) printf("("), a++;
        else printf(")"), tot+=mem[a+1][f], f++;
    }
    printf("\n");
    //printf("%llu\n", pd(0, 0));
    return 0;
}
