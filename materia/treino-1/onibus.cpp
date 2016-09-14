#include <cstdio>
#include <cstring>

#define MAX 1000000

unsigned long long n, K, L;

unsigned long long fib(unsigned long long n){ 
    unsigned long long fib[2][2] = {{K%MAX, L%MAX}, {1, 0}}, ret[2][2] = {{1,0}, {0,1}}, tmp[2][2] = {{0, 0}, {0, 0}};

    while(n){
        if(n&1){
            memset(tmp, 0, sizeof(tmp));
            for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
                tmp[i][j] = (tmp[i][j]+(ret[i][k]*fib[k][j])%MAX)%MAX;
            for(int i=0; i<2; i++) for(int j=0; j<2; j++)
                ret[i][j] = tmp[i][j];
        }
        memset(tmp, 0, sizeof(tmp));
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
            tmp[i][j] = (tmp[i][j] + (fib[i][k]*fib[k][j])%MAX)%MAX;
        for(int i=0; i<2; i++) for(int j=0; j<2; j++)
            fib[i][j] = tmp[i][j];
        n/=2;
    }   
    return ret[0][0];
}

int main () {
    while (scanf("%llu %llu %llu", &n, &K, &L) != EOF) {
        printf("%06llu\n", fib(n/5));
    }
    return 0;
}
