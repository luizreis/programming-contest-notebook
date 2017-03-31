#include <bits/stdc++.h>
using namespace std;

int n, b, ball[100], res[100];

int main() {
    while (scanf("%d %d", &n, &b) && (n || b)) {
        memset(res, 0, sizeof(res));
        for (int i = 0; i < b; i++) scanf("%d", ball+i);
        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
                res[abs(ball[i]-ball[j])] = 1;
        int c = 0;
        for (int i = 0; i <= n; i++) if (res[i]) c++;
        printf("%c\n", (c == n+1)?'Y':'N');
    }
    return 0;
}

