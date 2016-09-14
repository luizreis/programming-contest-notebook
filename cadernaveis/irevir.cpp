#include <stdio.h>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

#define MIN(a, b) ((a) < (b))?(a):(b)

int N, M, v, w, _w, p, C, idx;
int I[2001], LL[2001];
bool OS[2001];
stack<int> S;
vector<int> G[2001];

void strongconnect (int _v) {
    I[_v] = idx;
    LL[_v] = idx;
    idx++;
    S.push(_v);
    OS[_v] = true;

    for (int i = 0; i < G[_v].size(); i++) {
        if (I[G[_v][i]] == -1) {
            strongconnect(G[_v][i]);
            LL[_v] = MIN(LL[_v], LL[G[_v][i]]);
        } else if (OS[G[_v][i]]) {
            LL[_v] = MIN(LL[_v], I[G[_v][i]]);
        }
    }

    if (LL[_v] == I[_v]) {
        // start new scc
        C++;
        do {
            _w = S.top();
            S.pop();
            OS[_w] = false;
        } while (_w != _v);
    }

}

int main () { 
    scanf("%d %d", &N, &M);
    while (N != 0 || M != 0) {
        idx = 0;
        C = 0;
        for (int i = 1; i <= N; i++) G[i].clear();
        memset(I, -1, sizeof(I));
        memset(LL, -1, sizeof(LL));
        memset(OS, false, sizeof(OS));
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &v, &w, &p);
            G[v].push_back(w);
            if (p == 2) G[w].push_back(v);
        }
        
        for (int i = 1; i <= N; i++) {
            if (I[i] == -1) {
                strongconnect(i);
            }
        }

        printf("%d\n", (C>1)?0:1);
        scanf("%d %d", &N, &M);
    }
    return 0;
}
