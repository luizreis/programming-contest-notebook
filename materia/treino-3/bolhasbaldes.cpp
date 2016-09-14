#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;


int tree[100001];
int vec[100001];
int maxval=100001;

int read(int idx){
    int sum =0;
    while( idx > 0){
        sum+= tree[idx];
        idx-= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx <= maxval){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main(){

    int n,tmp;
    long long ac;

    while (scanf("%d",&n) && n){
        ac = 0;
        memset(tree,0,sizeof(tree));
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            ac += i - read(tmp);
            update(tmp, 1);
        }
        if(ac%2 == 0)
            printf("Carlos\n");
        else
            printf("Marcelo\n");
    }

    return 0;
}
