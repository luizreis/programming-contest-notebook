#include <bits/stdc++.h>
using namespace std;

int n, c;

int main() {
    scanf("%d", &n);
    for (int t=n; t>=0; t--) {
        c = 0;
        for (int p=2; p*p<=t && !c; p++) if (!(t%p)) c++;
        if (!c) { printf("%d\n", t); return 0; }
    }
    return 0;
}
