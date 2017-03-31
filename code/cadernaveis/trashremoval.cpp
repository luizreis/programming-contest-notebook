#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

typedef struct {
    int x, y;
} point;

bool cmpx(const point &p1, const point &p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

double cross(const point &o, const point &a, const point &b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double dist_line(const point &p, const point &a, const point &b) {
    return cross(b, a, p)/sqrt((b.y-a.y)*(b.y-a.y) + (b.x-a.x)*(b.x-a.x));
}

point p[101];
int n, tc = 0;

int main() {
    while (scanf("%d", &n) && n) {
        for (int i=0; i<n; i++) {
            scanf("%d %d", &(p[i].x), &(p[i].y));
        }
        // convex hull via monotone
        int k = 0;
        vector<point> h(2*n);
        sort(p, p+n, cmpx);
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && cross(h[k-2], h[k-1], p[i]) <= 0) k--;
            h[k++] = p[i];
        }
        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t && cross(h[k-2], h[k-1], p[i]) <= 0) k--;
            h[k++] = p[i];
        }
        h.resize(k);
        printf("k %d k depois %d\n", k, k-(n>1));
        k = k-(n>1);
        // rotate calipers
        double ans = 1e15;
        int j = 1;
        h[0] = h[k];
        for (int i = 1; i <= k; i++) {
            while (cross(h[i-1], h[i], h[j%k+1]) > cross(h[i-1], h[i], h[j]))
                j = j%k+1;
            printf("i %d j %d\n", i, j);
            ans = min (ans, dist_line(h[j], h[i], h[i-1]));
        }
        printf("Case %d: %.2lf\n", ++tc, ans);
    }
}
