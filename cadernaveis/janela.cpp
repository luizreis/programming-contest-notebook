#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define H 100
#define W 200
#define MAXW 600

bool in[MAXN];
pair<int, int> p[2*MAXN];


int main() {
    int n = 3, t, count = 0, last = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        p[i].first = t, p[i].second = i;
        p[i+n].first = t+W, p[i+n].second = i;
    }
    memset(in, false, sizeof(bool)*n);
    sort(p, p+2*n);
    for (int i = 0; i < 2*n; i++) {
        //printf("%s event for %d(%d)\n", (in[p[i].second])?"Out":"Entry", p[i].second, p[i].first);
        //printf("Current position %d, count %d, last %d\n", p[i].first, count, last);
        if (!in[p[i].second]) {
            // entry event
            if (count == 0) ans += (p[i].first-last)*H;
            in[p[i].second] = true;
            count++;
        } else {
            // out event
            count--;
            in[p[i].second] = false;
            last = p[i].first;
        }
    }
    ans += (MAXW-last)*H;
    printf("%d\n", ans);
    return 0;
}
