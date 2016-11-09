#include <bits/stdc++.h>
using namespace std;

int t, n, c;
double x, y, a;
char cmd[3];

int main() {
    scanf("%d", &t);
    while (t--) {
        x = y = a = 0.0;
        scanf("%d", &n);
        while (n--) {
            scanf("%s %d", cmd, &c);
            if (cmd[0] == 'f') x += cos(a)*c, y += sin(a)*c;
            if (cmd[0] == 'b') x -= cos(a)*c, y -= sin(a)*c;
            if (cmd[0] == 'l') a -= c*M_PI/180.0;
            if (cmd[0] == 'r') a += c*M_PI/180.0;
        }
        printf("%.0lf\n", sqrt(x*x+y*y));
    }
    return 0;
}
