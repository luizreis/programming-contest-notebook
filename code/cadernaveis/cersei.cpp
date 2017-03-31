#include <bits/stdc++.h>
using namespace std;

#define dist(p, x, y) (sqrt(((x)-(p))*((x)-(p))+(y)*(y)))

int n, p, x[50050], y[50050];
double a, b, m1, m2;

double mdist(double p) {
    double x_ = dist(p, x[0], y[0]);
    for (int i = 1; i < n; i++) {
        x_ = max(x_, dist(p, x[i], y[i]));
    }
    return x_;
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d %d", x+i, y+i);
    a = 0; b = p;
    for (int i = 0; i < 100; i++) {
        m1 = (a+((b-a)/3));
        m2 = (b-((b-a)/3));
        if (mdist(m1) < mdist(m2)) b = m2;
        else a = m1;
    }
    printf("%.2lf %.2lf\n", (a+b)/2, mdist((a+b)/2));
}
