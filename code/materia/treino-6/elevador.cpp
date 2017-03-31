#include <bits/stdc++.h>
using namespace std;

#define SQ(a) ((a)*(a))

int l, c, r1, r2;

int main() {
    while (scanf("%d %d %d %d", &l, &c, &r1, &r2) && (l || c || r1 || r2)) {
        int l1, l2;
        l1 = l-r1-r2;
        l2 = c-r1-r2;
        if (l < r1+r1 || c < r1+r1 || l < r2+r2 || c < r2+r2) printf("N\n");
        else printf("%c\n", (SQ(l1)+SQ(l2) >= SQ(r1+r2))?'S':'N');
    }
    return 0;
}
