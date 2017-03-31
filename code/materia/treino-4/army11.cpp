#include <bits/stdc++.h>
using namespace std;

set<int> sold;
set<int>::iterator li, ri, lr, rr;

int main () {
    int s, b, l, r;
    while (scanf("%d %d", &s, &b) && (s || b)) {
        for (int i = 1; i <= s; i++) sold.insert(i);
        for (int i = 0; i < b; i++) {
            scanf("%d %d", &l, &r);
            li = sold.find(l);
            ri = sold.find(r);
            lr = li;
            rr = ri;
            if (li == sold.begin()) {
                if (++ri == sold.end()) {
                    printf("* *\n");
                } else {
                    printf("* %d\n", *(ri));
                }
            } else {
                if (++ri == sold.end()) {
                    printf("%d *\n", *(--li));
                } else {
                    printf("%d %d\n", *(--li), *(ri));
                }
            }
            sold.erase(lr, ++rr);
        }
        printf("-\n");
    }
    return 0;
}
