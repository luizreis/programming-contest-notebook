#include <bits/stdc++.h>
using namespace std;

#define SQ(a) ((a)*(a))

const double EPS = 1e14;
const int MAXIT = 200;
int A, B, C, xc, yc;
double xf;

double f(double x) {
    double y = -(x*x)/A - (x)/B + C;
    return sqrt(SQ(xc-x)+SQ(yc-y));
}

double ternary(double l, double r) {
    int i = 0;
    double m1, m2;
    while (i < MAXIT) {
        m1 = l+(r-l)/3.0;
        m2 = r-(r-l)/3.0;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
        i++;
    }
    return (l+r)/2.0;
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d", &xc, &yc);
    scanf("%lf", &xf);
    double X = ternary(0.0, xf);
    double Y = -(X*X)/A - (X)/B + C;
    printf("%.2lf\n", sqrt(SQ(xc-X)+SQ(yc-Y)));
    return 0;
}
