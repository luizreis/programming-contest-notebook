#include <bits/stdc++.h>
using namespace std;

int t, n, f, r, q;
double mv, ia, ib, ih, vol[10010];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &f);
        for (int i = 0; i < n; i++) {
            scanf("%d", &r);
            vol[i] = M_PI*r*r;
            if (!i) mv = vol[i];
            mv = max(mv, vol[i]);
        }
        ia = 0.0;
        ib = mv;
        for (int i = 0; i < 80; i++) {
            q = 0;
            ih = (ia+ib)/2.0;
            for (int j = 0; j < n; j++) q += floor(vol[j]/ih);
            if (q <= f) ib = ih;
            else ia = ih;
        }
        printf("%.4lf\n", (ia+ib)/2);
    }
}
