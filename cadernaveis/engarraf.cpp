#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int G[110][110];
bool V[110];
int N, M, D = -1;
int a, b, t, c, d;
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

int main () {
    scanf("%d %d", &N, &M);
    while (N != 0 || M != 0) {
        D = -1;
        Q = priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >();
        memset(G, -1, sizeof(G));
        memset(V, false, sizeof(V));
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &a, &b, &t);
            G[a][b] = t;
        }
        scanf("%d %d", &a, &b);
        
        Q.push(make_pair(0, a));
        while (!Q.empty()) {
            if (!V[Q.top().second]) {
                c = Q.top().second;
                d = Q.top().first;
                V[c] = true;
                if (c == b) {
                    D = d;
                    break;
                }

                for (int i = 0; i <= N; i++)
                    if (G[c][i] != -1)
                        Q.push(make_pair(d + G[c][i], i));
            }
            Q.pop();
        }

        printf("%d\n", D);

        scanf("%d %d", &N, &M);
    }
    return 0;
}

