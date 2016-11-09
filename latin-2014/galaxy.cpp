#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map <int, unordered_map <int, int> > S;
int cx[50010], cy[50010];
vector <int> adj[50010];

int foi[50010];
int c1, c2;

void dfs(int u, int c){
    foi[u] = -1;

    if(c) c1++;
    else c2++;

    for(int i=0; i<adj[u].size(); i++)
    if(!foi[adj[u][i]])
        dfs(adj[u][i], 1-c);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int x, y;
        scanf("%d %d", cx+i, cy+i);
        S[cx[i]][cy[i]] = i;
    }

    for(int i=1; i<=n; i++){
        for(int k=-5; k<=5; k++)
        for(int j=-5; j<=5; j++){
            if(!k && !j) continue;
            if(k*k + j*j > 25) continue;

            auto x = S.find(cx[i]+k);
            if (x != S.end() && x->second.find(cy[i]+j) != x->second.end())
                adj[i].push_back(S[cx[i]+k][cy[i]+j]);
        }
    }

    memset(foi, 0, sizeof(foi));
    int ans = 0;
    for(int i=1; i<=n; i++)
    if(!foi[i]){
        c1 = c2 = 0;
        dfs(i, 0);
        ans += min(c1, c2);
    }

    printf("%d\n", ans);

    return 0;
}
