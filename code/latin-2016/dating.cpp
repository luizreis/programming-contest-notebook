#include <bits/stdc++.h>
using namespace std;

int n, s[100010], p[100010];
double area = 0, sum = 0, sub = 0;

double ang(int i) { return i*2*M_PI/n; }
double x(int i) { return -sin(ang(i))*p[i]; }
double y(int i) { return cos(ang(i))*p[i]; }

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", s+i);
    sort(s, s+n);
    for (int i=0; i<n; i++) {
        if (!(i&1)) p[i/2] = s[i];
        else p[n-1-i/2] = s[i];
    }
    for (int i=0, j=n-1; i<n; i++)
        area += (x(j)+x(i))*(y(j)-y(i)), j=i;
    printf("%.3lf\n", fabs(area/2.0));
    return 0;
}
