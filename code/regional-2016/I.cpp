#include <bits/stdc++.h>
using namespace std;

#define MAX 50050
int n, col[MAX], dir[MAX], esq[MAX];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", col+i);

    esq[0] = col[0] ? 1 : 0;
    for(int i=1; i<n; i++)
        esq[i] = (col[i] > esq[i-1]) ? esq[i-1]+1 : col[i];

    dir[n-1] = col[n-1] ? 1 : 0;
    for(int i=n-2; i>=0; i--)
        dir[i] = (col[i] > dir[i+1]) ? dir[i+1]+1 : col[i];

    int m = 0;
    for(int i=0; i<n; i++){
        int men = min(esq[i], dir[i]);
        m = max(men, m);
    }

    printf("%d\n", m);

    return 0;
}
