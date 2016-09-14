#include <bits/stdc++.h>
using namespace std;

int est[50000][8], ne;

int ini[8];

bool comp(int *va, int *vb){
    int i;
    for(i=0; i < 8 && (va)[i] == (vb)[i]; i++);
    if(i == 8) return false;
    return (va)[i] < (vb)[i];
}

map <int*, int, bool(*) (int*, int*)> MAP(&comp);

long long dij(){
    priority_queue <pair <long long, int> > fila;
    long long dist[50050];
    bool vis[50050];
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));

    int tmp[8];

    dist[0] = 0;
    fila.push(make_pair(0, 0));
    while(!fila.empty()){
        int p = fila.top().second;
        if(p == 1) return dist[p];
        fila.pop();

        if(vis[p]) continue;
        vis[p] = true;

        for(int i=0; i<8; i++)
            tmp[i] = est[p][i];

        for(int i=0; i<3; i++){
            swap(tmp[i], tmp[i+1]);
            if(MAP.find(tmp) == MAP.end()){
                for(int j=0; j<8; j++) est[ne][j] = tmp[j];
                MAP[est[ne]] = ne;
                ne++;
            }
            int td = dist[p] + tmp[i] + tmp[i+1];
            int u = MAP[tmp];
            if(td < dist[u]){
                dist[u] = td;
                fila.push(make_pair(-td, u));
            }
            swap(tmp[i], tmp[i+1]);
        }
        for(int i=4; i<7; i++){
            swap(tmp[i], tmp[i+1]);
            if(MAP.find(tmp) == MAP.end()){
                for(int j=0; j<8; j++) est[ne][j] = tmp[j];
                MAP[est[ne]] = ne;
                ne++;
            }
            int td = dist[p] + tmp[i] + tmp[i+1];
            int u = MAP[tmp];
            if(td < dist[u]){
                dist[u] = td;
                fila.push(make_pair(-td, u));
            }
            swap(tmp[i], tmp[i+1]);
        }
        for(int i=0; i<4; i++){
            swap(tmp[i], tmp[i+4]);
            if(MAP.find(tmp) == MAP.end()){
                for(int j=0; j<8; j++) est[ne][j] = tmp[j];
                MAP[est[ne]] = ne;
                ne++;
            }
            int td = dist[p] + tmp[i] + tmp[i+4];
            int u = MAP[tmp];
            if(td < dist[u]){
                dist[u] = td;
                fila.push(make_pair(-td, u));
            }
            swap(tmp[i], tmp[i+4]);
        }
    }
}

int main(){
    for(int i=0; i<8; i++)
        scanf("%d", est[0]+i);
    for(int i=0; i<8; i++)
        scanf("%d", est[1]+i);

    MAP[est[0]] = 0;
    if(MAP.find(est[1]) == MAP.end()){
        MAP[est[1]] = 1;

        ne = 2;

        printf("%lld\n", dij());
    }else{
        printf("0\n");
    }

    return 0;
}
