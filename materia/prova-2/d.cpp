#include <bits/stdc++.h>


using namespace std;

int aa[40], vv[40], n;
int MEM[40][850][850];

int pd(int i, int a, int v){
    int ar, vr;
    ar = a;
    vr = v;
    if (i >= n ) return 0;
    if(MEM[i][a][v] != -1) return MEM[i][a][v];

    int opc1, opc2;
    opc1 = pd(i+1, a,v);
    opc2 = -1;
    if(a >= -aa[i] && v >= -vv[i]){
        ar += aa[i];
        vr += vv[i];
        opc2 = 1 + pd(i+1, ar,vr);
    }
    MEM[i][a][v] = max(opc1, opc2);
    return MEM[i][a][v];
}

int main(){
    int a, v;
    scanf("%d", &n);

    scanf("%d %d", &v, &a);

    for(int i = 0; i< n; i++)
        scanf("%d %d", vv+i, aa+i);
    memset(MEM,-1,sizeof(MEM));

    printf("%d\n", pd(0,a,v));

    return 0;
}
