#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, g;
    while (scanf("%d", &a) != EOF) {
        int c = 0;
        for (int i=0; i<5; i++) {
            scanf("%d", &g);
            if (g == a) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
