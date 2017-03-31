#include <bits/stdc++.h>
using namespace std;

int n, g, dif[100010], s, r;

int main() {
    while (scanf("%d %d", &n, &g) != EOF) {
        int ans = 0;
        for (int i =0; i < n; i++) {
            scanf("%d %d", &s, &r);
            dif[i] = s-r;
        }
        sort(dif, dif+n);
        for (int i = n-1; i >= 0; i--) {
            if (dif[i] > 0) {
                ans += 3;
            } else if (dif[i] == 0) {
                if (g > 0) ans+= 3, g--;
                else ans++;
            } else {
                if (g + dif[i] - 1 >= 0) g += dif[i] - 1, ans += 3;
                else if (g + dif[i] >= 0) g+= dif[i], ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
