#include <bits/stdc++.h>

using namespace std;

#define msz(a) (memset(a, 0, sizeof (a)))

int n, m, t;
int ini[2], fim[2];

int main () {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            scanf("%d", &t);
            if(t == 2) ini[0] = i, ini[1] = j;
            if(t == 1) fim[0] = i, fim[1] = j;
        }
    printf("%d\n", abs(fim[0]-ini[0])+abs(fim[1]-ini[1]));
    return 0;
}
