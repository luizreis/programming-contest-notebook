#include <cstdio>

int k, n, m ,x, y;

int main(){
    while(scanf("%d", &k) && k){
        scanf("%d %d", &n, &m);
        for(int i=0; i<k; i++){
            scanf("%d %d", &x, &y);
            if((x == n) || (y == m)) printf("divisa\n");
            else if(x < n){
                if(y < m){
                    printf("SO\n");
                }else{
                    printf("NO\n");
                }
            }else{
                if(y < m){
                    printf("SE\n");
                }else{
                    printf("NE\n");
                }
            }
        }
    }
    return 0;
}
