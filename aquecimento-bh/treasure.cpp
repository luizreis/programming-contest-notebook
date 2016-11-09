#include <bits/stdc++.h>
using namespace std;

int r, c;
char m[201][201], a;

int main() {
    scanf("%d %d", &r, &c);
    for (int i=0; i<r; i++) scanf("%s", m[i]);
    int step = 0, x = 0, y = 0;
    while (step < 50000) {
        if (x<0 || y<0 || x>=r || y>=c) { printf("Out\n"); return 0; }
        a = m[x][y];
        if (a == 'N') x--;
        else if (a == 'S') x++;
        else if (a == 'W') y--;
        else if (a == 'E') y++;
        else if (a == 'T') { printf("%d\n", step); return 0; }
        step++;
    }
    printf("Lost\n");
    return 0;
}
