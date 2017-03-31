#include <cstdio>

int main () {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("1");
        for (int i = 2; i * i <= n; i++) {
            printf(" %d", i*i);
        }
        printf("\n");
    }
    return 0;
}
