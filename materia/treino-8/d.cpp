#include <bits/stdc++.h>
using namespace std;

#define MAX 50050

int n, x, X[MAX], Y[MAX];

double d(double p, int i){
    return sqrt((X[i]-p)*(X[i]-p)+Y[i]*Y[i]);
}


double dist(double x) {
    double p = d(x, 0);
    for (int i=1; i<n; i++) p = max(p, d(x, i));
    return p;
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i=0; i<n; i++) scanf("%d %d", X+i, Y+i);
    double a, b, m1, m2;
    a = 0; b = x;
    for (int i=0; i<100; i++) {
        m1 = (a+((b-a)/3));
        m2 = (b-((b-a)/3));
        if (dist(m1) < dist(m2)) b = m2;
        else a = m1;
    }
    printf("%.2lf %.2lf\n", (a+b)/2, dist((a+b)/2));
    return 0;
}
