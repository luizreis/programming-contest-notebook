#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    long long mod[3], sum = 0, ans = 0;
    memset(mod, 0, sizeof mod);
    mod[0] = 1;
    while (scanf("%c", &c) && c != '\n') {
        if (isdigit(c)) {
            sum = (sum + c - '0') %3;
            ans += mod[sum];
            mod[sum]++;
        } else {
            memset(mod, 0, sizeof mod);
            mod[0] = 1;
            sum = 0;
        }
    }
    printf("%lld\n", ans);
}
