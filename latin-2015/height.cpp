#include <bits/stdc++.h>
using namespace std;

int r, c, v[128][128], vis[128][128];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void fill(int alt, int x, int y){
    if(x < 0 || x >= r || y < 0 || y >= c) return;
    if(v[x][y] != alt) return;
    if(vis[x][y]) return;
    vis[x][y] = -1;

    for(int i=0; i<4; i++)
        fill(alt, x+dx[i], y+dy[i]);
}

int main(){
    while(scanf("%d %d", &r, &c) != EOF){
        for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d", v[i]+j);

        long long qtd = 1;

        memset(vis, 0, sizeof vis);
        for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(!vis[i][j])
                qtd++, fill(v[i][j], i, j);

        qtd++;
        for(int i=1; i<r; i++){
            long long d1 = v[i][0] - v[i-1][0];
            qtd += (d1 ? 1 : 0);
            for(int j=1; j<c; j++){
                long long d2 = v[i][j] - v[i-1][j];
                if(d1*d2 < 0) qtd++;
                else if(d1*d2 > 0){
                    if(max(v[i][j], v[i-1][j]) <= min(v[i][j-1], v[i-1][j-1])) qtd++;
                    else if(max(v[i][j-1], v[i-1][j-1]) <= min(v[i][j], v[i-1][j])) qtd++;
                }else if(!d1 && d2) qtd++;

                d1 = d2;
            }
        }
        qtd++;

        qtd++;
        for(int j=1; j<c; j++){
            long long d1 = v[0][j] - v[0][j-1];
            qtd += (d1 ? 1 : 0);
            for(int i=1; i<r; i++){
                long long d2 = v[i][j] - v[i][j-1];
                if(d1*d2 < 0) qtd++;
                else if(d1*d2 > 0){
                    if(max(v[i][j], v[i][j-1]) <= min(v[i-1][j-1], v[i-1][j])) qtd++;
                    else if(max(v[i-1][j-1], v[i-1][j]) <= min(v[i][j], v[i][j-1])) qtd++;
                }else if(!d1 && d2) qtd++;

                d1 = d2;
            }
        }
        qtd++;

        printf("%lld\n", qtd);
    }
    return 0;
}
