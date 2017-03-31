#include <bits/stdc++.h>
using namespace std;

int v, a;
int c[10001];
vector <int> adj[10001];
set <int> matcmp[10001];
vector <int> cmp[100001];
char foidivi[100001];
vector <int> divi;

int gcd(int a, int b){
    int r;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

char foi[10001];
int dfs(int k, int u){
    foi[u] = 1;

    int g = c[u];
    for(int i=0; i<adj[u].size(); i++)
    if(matcmp[adj[u][i]].find(k) != matcmp[adj[u][i]].end() && !foi[adj[u][i]]){
        matcmp[adj[u][i]].erase(k);
        g = gcd(g, dfs(k, adj[u][i]));
    }
    return g;
}

int valido(int k){
    memset(foi, 0, sizeof foi);
    for(int i=0; i<cmp[k].size(); i++)
    if(!foi[cmp[k][i]])
    if(dfs(k, cmp[k][i]) == k) return true;
    return false;
}

int main(){
    while(scanf("%d %d", &v, &a) != EOF){
        memset(foidivi, 0, sizeof foidivi);
        for(int i=1; i<=v; i++) adj[i].clear();
        for(int i=0; i<100001; i++) cmp[i].clear();
        for(int i=0; i<10001; i++) matcmp[i].clear();
        divi.clear();

        for(int i=1; i<=v; i++) scanf("%d", c+i);
        for(int i=0; i<a; i++){
            int t1, t2;
            scanf("%d %d", &t1, &t2);
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
        }

        for(int i=1; i<=v; i++)
        for(int j=1; j*j<=c[i]; j++)
        if(!(c[i]%j)){
            matcmp[i].insert(j);
            matcmp[i].insert(c[i]/j);
            cmp[j].push_back(i);
            cmp[c[i]/j].push_back(i);

            if(!foidivi[j]){
                foidivi[j] = 1;
                divi.push_back(j);
            }
            if(!foidivi[c[i]/j]){
                foidivi[c[i]/j] = 1;
                divi.push_back(c[i]/j);
            }
        }

        int ans = 0;
        for(int i=0; i<divi.size(); i++)
        if(valido(divi[i])) ans++;

        printf("%d\n", ans);
    }
    return 0;
}
