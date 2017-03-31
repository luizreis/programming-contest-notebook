// N is the maximum X
// M is the maximum Y
// tree is the array where the BIT is stored
// tree has to be cleared

#include <bits/stdc++.h>
using namespace std;

const int N = 1001, M = 1001;

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
            // modify to the operation needed (max, min, etc.)
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}

int main() {
    memset(tree, 0, sizeof(tree));

    return 0;
}
