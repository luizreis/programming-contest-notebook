#include <bits/stdc++.h>

using namespace std;

#define msz(a) (memset(a, 0, sizeof (a)))

int n, c = 0;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        c += a;
    }
    if (c*3 >= n*2) printf("impeachment\n");
    else printf("acusacao arquivada\n");
    return 0;
}
