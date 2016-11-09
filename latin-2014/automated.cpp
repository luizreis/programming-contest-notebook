#include <bits/stdc++.h>

using namespace std;


int main(){
    int v[10];
le:
    for(int i =0 ; i < 10; i++) if(scanf("%d", v+i) == EOF) return 0;

    for (int i= 0; i< 5; i++){
        if((v[i] && v[i+5]) || (!v[i] && !v[i+5])) goto nao;
    }
    printf("Y\n");
    goto le;
nao:
    printf("N\n");
    goto le;
}
