#include <bits/stdc++.h>
using namespace std;

const int N = 1002, M = 1002;

int tree[N][M];

void update(int x, int y, int v) {
    int y1;
    while (x < N) {
        y1 = y;
        while (y1 < M) {
            tree[x][y1] += v;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int read(int x, int y) {
    int sum = 0;
    while (x) {
        int y1 = y;
        while (y1) {
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}

int n, m;

int main() {
    memset(tree, 0, sizeof(tree));
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp != 0) update(i+1, j+1, 1);
        }
    }
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        update(a, b, 1);
        scanf("%d %d", &a, &b);
        printf("%d\n", read(a, b));
    }
    return 0;
}
