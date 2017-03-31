#include <bits/stdc++.h>

using namespace std;

#define msz(a) (memset(a, 0, sizeof (a)))

int tree[300010];
int vec[300010];
int maxval=300001;

int read(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int i, int v){
    while(i <= maxval){
        tree[i] += v;
        i += (i&-i);
    }
}

int ip, m, pc, na;

int main () {
    memset(tree, 0, sizeof(tree));
    scanf("%d %d", &ip, &m);
    int c=0;
    for(int i=0; i<m; i++){
        scanf("%d %d", &pc, &na);
        if(read(pc+ip)-(pc-ip-1 > 0 ? read(pc-ip-1) : 0) <= na){
            update(pc, 1);
            c++;
        }
    }
    printf("%d\n", c);

    return 0;
}
