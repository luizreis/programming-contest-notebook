#include <bits/stdc++.h>
using namespace std;

#define INF 10000

typedef struct {
  double x, y;
} point;

bool cmpx(const point &p1, const point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool cmpy(const point &p1, const point &p2) {
  return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

double dist(const point &a, const point &b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int n;
point p[10010], strip[10010];

double closest_pair(int l, int r) {
    if (l >= r) return INF;
    if (l == r - 1) return dist(p[l], p[r]);
    int mid = (l+r)/2;
    double dl = closest_pair(l, mid);
    double dr = closest_pair(mid+1, r);
    double d = min(dl, dr);
    // get points on strip
    int c = 0;
    for (int i = l; i <= r; i++)
        if (fabs(p[i].x - p[mid].x) < d) strip[c++] = p[i];
    sort(strip, strip+c, cmpy);
    // h < 7 as there are at max 6 points on the strip rectangle
    for (int i = 0; i < c; i++)
        for (int j = i+1, h = 0; j < c && h < 7; j++, h++)
            d = min(d, dist(strip[i], strip[j]));
    return d;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) scanf("%lf %lf", &(p[i].x), &(p[i].y));
        sort(p, p+n, cmpx);
        double ans = closest_pair(0, n-1);
        if (ans >= 10000) printf("INFINITY\n");
        else printf("%.4lf\n", ans);
    }
    return 0;
}
