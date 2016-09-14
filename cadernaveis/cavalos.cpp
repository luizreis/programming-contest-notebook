#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

#define INFINITY 0x3f3f3f3f
#define MIN(a, b) ((a)<(b))?(a):(b)

using namespace std;

typedef struct {
    int s, t, cap, flow;
} edge;

int n, m, k, c, u, v, in;
vector<int> g[202];
int cap[202][202], flow[202][202];

int karp (int s, int t) {
    int mflow = 0, cur, df, to, prev;
    queue<int> q;
    int pred[202];
    while (true) {
        memset(pred, -1, sizeof(pred));
        q.push(s);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < g[cur].size(); i++) {
                to = g[cur][i];
                if (pred[to] == -1 && to != s && cap[cur][to] > flow[cur][to]) {
                    pred[to] = cur;
                    q.push(to);
                }
            }
        }
        if (pred[t] == -1) break;
        df = INFINITY;
        cur = t;
        while (pred[cur] != -1) {
            prev = pred[cur];
            df = MIN(df, cap[prev][cur] - flow[prev][cur]);
            cur = prev;
        }
        cur = t;
        while (pred[cur] != -1) {
            prev = pred[cur];
            flow[prev][cur] += df;
            flow[cur][prev] -= df;
            cur = prev;
        }
        mflow += df;
    }
    return mflow;
}

int main () {
    in = 1;
    while(scanf("%d %d %d", &n, &m, &k) != EOF) {
        for (int i = 0; i < 202; i++) g[i].clear();
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        for (int i = 1; i <= m; i++) {
            g[0].push_back(i);
            g[i].push_back(0);
            cap[0][i] = 1;
            cap[i][1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            // i-esimo cavalo monta #sold
            scanf("%d", &c);
            g[i+100].push_back(201);
            g[201].push_back(i+100);
            cap[i+100][201] = c;
            cap[201][i+100] = 0;
        }
        for (int i = 1; i <= k; i++) {
            scanf("%d %d", &u, &v);
            g[u+100].push_back(v);
            g[v].push_back(u+100);
            cap[u+100][v] = 0;
            cap[v][u+100] = 1;
        }
        
        printf("Instancia %d\n%d\n", in, karp(0, 201));
        in++;
    }
    return 0;
}

