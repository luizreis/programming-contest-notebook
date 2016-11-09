#include <bits/stdc++.h>

using namespace std;

int VS[5010];



int main(){
    int n;
    memset(VS,0,sizeof(VS));
    for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                    if(i==0 && j==0 && k==0 && l!=0){
                        n = i*1000+j*100+k*10+l;
                        for(n; n<=5000; n++) VS[n]++;
                    } else if( i==0 && j==0 && k!=l) {
                        n = i*1000+j*100+k*10+l;
                        for(n; n<=5000; n++) VS[n]++;
                    } else if( i==0 && j!=k && j!=l && k!=l){
                        n = i*1000+j*100+k*10+l;
                        for(n; n<=5000; n++) VS[n]++;
                    }else if((i!=j && i!=k && i!=l) && j!=k && j!=l && k!=l){
                        n = i*1000+j*100+k*10+l;
                        for(n; n<=5000; n++) VS[n]++;
                    }
                }
            }
        }
    }
    int a, b;
    while(scanf("%d %d", &a,&b) != EOF)
    printf("%d\n",VS[b] - VS[a-1]);
    return 0;
}
