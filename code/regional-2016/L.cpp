#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int h, l;
int mat[200][200];
int vis[200][200];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int busca(int i, int j, int c){
    if(i < 0 || i >= h || j < 0 || j >= l) return 0;
    if(mat[i][j] != c) return 0;
    if(vis[i][j]) return 0;

    vis[i][j] = -1;

    int acc = 0;
    for(int x=0; x<4; x++)
        acc += busca(i+dx[x], j+dy[x], c);
    return 1+acc;
}

int main(){
    scanf("%d %d", &h, &l);
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
            scanf("%d", mat[i]+j);

    memset(vis, 0, sizeof(vis));
    int mencor = INF;
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
            if(!vis[i][j])
                mencor = min(mencor, busca(i, j, mat[i][j]));

    printf("%d\n", mencor);

    return 0;
}
