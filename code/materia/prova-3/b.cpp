#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, c, l;
    scanf("%d %d %d %d", &n, &h, &c, &l);
    double area = sqrt(h*h+c*c)*l;
    printf("%.4lf\n", area*n/10000.0);
    return 0;
}
