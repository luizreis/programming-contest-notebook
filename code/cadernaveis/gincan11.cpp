#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int n, m, t1, t2, C=0;
bool V[1001];
vector<int> G[1001];

void dfs (int v) {
    if (V[v] == false) {
        V[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            dfs (G[v][i]);
        }
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t1, &t2);
        G[t1-1].push_back(t2-1);
        G[t2-1].push_back(t1-1);
    }
    memset(V, false, sizeof(V));
    for (int i = 0; i < n; i++) {
        if (V[i] == false) {
            dfs(i);
            C++;
        }
    }
    printf("%d\n", C);
    return 0;
}

