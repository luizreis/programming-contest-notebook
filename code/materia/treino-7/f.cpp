#include <bits/stdc++.h>
using namespace std;

int n, xs, ys, vs, vc;
double x[50050], y[50050];
double t[50050];

#define SQ(a) ((a)*(a))
#define EPS 1e-9

double dist(int i, int j) {
    return sqrt(SQ(x[i]-x[j]) + SQ(y[i]-y[j]));
}

int reach(int s, double xi) {
    double T = t[s]-t[s-1];
    double porc = (xi-t[s-1])/T;

    double A = x[s-1] + (x[s] - x[s-1])*porc;
    double B = y[s-1] + (y[s] - y[s-1])*porc;
    //printf("A %.2lf B %.2lf porc %.2lf",A,B,porc);

    double tsk = sqrt(SQ(xs-A)+SQ(ys-B))/vs;
    
    //if(tsk <= xi) printf("1");
    //else printf("0");

    //printf(" %.4lf %.4lf\n",xi, tsk);
    return tsk <= xi;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d", &xs, &ys);
    for (int i=0; i<n; i++) scanf("%lf %lf", x+i, y+i);
    scanf("%d %d", &vs, &vc);
    t[0] = 0;
    for (int i=1; i<=n; i++) {
        t[i] = t[i-1] + dist(i-1, i)/vc;
        //printf("t[%d] = %.3lf\n", i, t[i]);
    }
    int s;
    for (s=1; s<n; s++) {
        double ts = sqrt(SQ(xs-x[s])+SQ(ys-y[s]))/vs;
        if (ts <= t[s]) break;
    }
    if (s >= n) { printf("impossivel\n"); return 0; }

    double a = t[s-1], b = t[s];
    //printf("inicio %.2lf fim %.2lf\n", a, b);
    int it = 0;
    while (fabs(a-b) > EPS && it++ < 80) {
        double m = (a+b)/2;
        if (reach(s, m)) b = m;
        else a = m;
    }

    //printf("\n%d\n\n",reach(2,5.90));
    printf("%.2lf\n", (a+b)/2);
    return 0;
}
