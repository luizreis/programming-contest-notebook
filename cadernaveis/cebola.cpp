#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y;
} point;

bool compare(const point &p1, const point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int cross(const point &o, const point &a, const point &b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// on real convex hull, should return the points (vector<point>)
// used vector is not used on real c_hull
vector<int> convex_hull(vector<point> &P, vector<bool> &used) {
  int n = P.size(), k = 0;
  vector<int> H(2*n); // vector<point>

  sort(P.begin(), P.end(), compare);

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue; // not used on real c_hull
    while (k >= 2 && cross(P[H[k-2]], P[H[k-1]], P[i]) < 0) k--;
    H[k++] = i; // i should be P[i]
  }

  for (int i = n-2, t = k+1; i >= 0; i--) {
    if (used[i]) continue; // not used on real c_hull
    while (k >= t && cross(P[H[k-2]], P[H[k-1]], P[i]) < 0) k--;
    H[k++] = i; // i should be P[i]
  }

  H.resize(k);
  return H;
}

int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    vector<point> P(n);
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
      used[i] = false;
      scanf("%d %d", &(P[i].x), &(P[i].y));
    }

    int ans = 0;
    while (true) {
      // should be vector<point> when using real c_hull
      vector<int> C = convex_hull(P, used);
      if (!C.size()) break;
      for (int i = 0; i < C.size(); i++) { // not used on real c_hull
        used[C[i]] = true; // not used on real c_hull
      } // not used on real c_hull
      ans++; 
    }

    if (ans&1) printf("Take this onion to the lab!\n");
    else printf("Do not take this onion to the lab!\n");
  }
  return 0;
}
