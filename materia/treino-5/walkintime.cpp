#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a==b || b==c || a==c || a+b==c || b+c==a || a+c==b)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
