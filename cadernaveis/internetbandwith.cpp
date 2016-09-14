#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

#define MIN(a, b) ((a) < (b))?(a):(b)
#define INFINITY 0x3f3f3f3f

int n, s, t, c, x, y, b, id = 0;
long long int mflow = 0, pathcap;
vector<int> G[101];
long long int cap[101][101];

int findpath() {
    queue<int> Q;
    int F[101], w, p, n;
    bool V[101];
    memset(V, false, sizeof(V));
    memset(F, -1, sizeof(F));
    Q.push(s);
    V[s] = true;

    while (!Q.empty()) {
        w = Q.front();
        Q.pop();
        for (int i = 0; i < G[w].size(); i++) {
            n = G[w][i];
            if (!V[n] && cap[w][n] > 0) {
                Q.push(n);
                V[n] = true;
                F[n] = w;
                if (n == t) goto end_while;
            }
        }
    }
    end_while:
    w = t;
    pathcap = INFINITY;
    while (F[w] != -1) {
        p = F[w];
        pathcap = MIN(pathcap, cap[p][w]);
        w = p;
    }
    w = t;
    while (F[w] != -1) {
        p = F[w];
        cap[p][w] -= pathcap;
        cap[w][p] += pathcap;
        w = p;
    }
    if (pathcap == INFINITY) return 0;
    else return pathcap;
}

int main () {
    scanf("%d", &n);
    while (n != 0) {
        memset(cap, 0, sizeof(cap));
        mflow = 0;
        printf("Network %d\n", ++id);
        scanf("%d %d %d", &s, &t, &c);
        for (int i = 0; i < c; i++) {
            scanf("%d %d %d", &x, &y, &b);
            G[x].push_back(y);
            G[y].push_back(x);
            cap[x][y] += b;
            cap[y][x] += b;
        }

        while (true) {
            pathcap = findpath();
            if (pathcap == 0) break;
            else mflow += pathcap;
        }

        printf("The bandwidth is %lld.\n\n", mflow);
        scanf("%d", &n);
    }
    return 0;
}
