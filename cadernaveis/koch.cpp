#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, r;
    char in[1000001];
    int fib[1501] = {0, 1};
    // pre calc fib
    for (int i = 2; i <= 1500; i++) fib[i] = (fib[i-1] + fib[i-2])%1000;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", in);
        n = strlen(in); r = 0;
        for (int i = 0; i < n; i++)
            r = (r*10 + in[i]-'0')%1500;
        printf("%03d\n", fib[r]);
    }
    return 0;
}
