#include <stdio.h>

int i, j, k;
int n, m;
int mat[101][101];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    for(j=0; j<m; j++)
        scanf("%d", mat[i]+j);

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(mat[i][j]){
                printf("9");
                continue;
            }

            int c=0;
            for(k=0; k<4; k++){
                int x = i+dx[k], y = j+dy[k];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                c+=mat[x][y];
            }
            printf("%d", c);
        }
        printf("\n");
    }

    return 0;
}
