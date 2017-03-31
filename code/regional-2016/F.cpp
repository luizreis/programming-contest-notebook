#include<bits/stdc++.h>
using namespace std;

int a[2][10010][2];

void conta(int j, int i, int c, int *var){
    if(a[j][i][1] == 0)
        *var = max(*var, c);
    else
        conta(j,a[j][i][1],c+1,var);

    if(a[j][i][0])
        conta(j,a[j][i][0], 1, var);
}

int contar(int j){
    int t = 1;
    int ac = 1;
    while(a[j][t][1]){
        t = a[j][t][1];
        ac++;
    }
    return ac;
}

int main(){
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n); int I,J,K;
    for(int i=0; i< n; i++){
        scanf("%d",&I);
        scanf("%d %d", &a[0][I][0], &a[0][I][1]);
    }
    int m;
    scanf("%d",&m); int P,Q,R;
    for(int i=0; i < m; i++){
        scanf("%d",&P);
        scanf("%d %d", &a[1][P][1], &a[1][P][0]);
    }

    int maior_can_r, maior_can = 0, maior_des_r, maior_des= 0;
    maior_can_r = contar(0);
    maior_des_r = contar(1);
    conta(0,1,1,&maior_can);
    conta(1,1,1,&maior_des);

    //printf("Maior raiz: can(%d), des(%d)\n",maior_can_r,maior_des_r);
    //printf("Maior: can(%d), des(%d)\n", maior_can, maior_des);
    int enr_can = m + n - min(maior_des, maior_can_r);
    int enr_des = m + n - min(maior_can, maior_des_r);

    printf("%d\n",min(enr_can,enr_des));

    return 0;
}
