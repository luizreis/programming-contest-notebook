#include <bits/stdc++.h>
using namespace std;

char mapa[101][101];
char vis[101][101][1<<8];
int h = -1, w;

void set_key(char c, int *b) {
    int i = c - 'a';
    *b = *b|(1<<i);
}

int has_key(char c, int b) {
    int i = c - 'A';
    return ((b>>i)&1);
}

int bfs(int i, int j) {
    int x, y, b, m;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    char c;
    queue< pair< pair<int, int> , pair<int, int> > > fila;
    fila.push(make_pair(make_pair(i, j), make_pair(0, 0)));
    while (!fila.empty()) {
        x = fila.front().first.first;
        y = fila.front().first.second;
        b = fila.front().second.first;
        m = fila.front().second.second;
        fila.pop();
        if (x < 0 || y < 0 || x >= h || y >= w) continue;
        if (vis[x][y][b]) continue;
        vis[x][y][b] = (char)1;
        c = mapa[x][y];
        if (c == '*') return m;
        if (c == '#') continue;
        if (c >= 'a' && c <= 'g') set_key(c, &b);
        if (c >= 'A' && c <= 'G') if (!has_key(c, b)) continue;
        for (int k = 0; k < 4; k++)
            fila.push(make_pair(make_pair(x+dx[k], y+dy[k]), make_pair(b, m+1)));
    }
    return -1;
}

int main() {
    int x, y, ans;
    while (scanf("%s", mapa[++h]) != EOF);
    w = strlen(mapa[0]);
    // locate start
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (mapa[i][j] == '@') {x = i; y = j;}
    memset(vis, 0, sizeof(vis));
    ans = bfs(x, y);
    if (ans == -1) printf("--\n");
    else printf("%d\n", ans);
    return 0;
}
