#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, t;
    char str[100];
    scanf("%d %d", &p, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int flag = 1;
        for (int j = 0; j < p; j++) {
            scanf("%d", &t);
            if (!t) flag = 0;
        }
        if (flag) {
            printf("%s\n", str);
            goto fim;
        }
    }
    printf("Pizza antes de FdI\n");
fim:
    return 0;
}
