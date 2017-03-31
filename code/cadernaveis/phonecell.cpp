#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7
#define SQ(a) ((a)*(a))

typedef struct {
    double ang;
    int p;
} angle;

bool cmpa(const angle &a1, const angle &a2) { return a1.ang < a2.ang; }

int n, r;
int x[2002], y[2002];

double ang(const int i, const int j) {
    if(x[i]==x[j]) {
        if(y[j]>y[i]) return M_PI/2; else return 3*M_PI/2;
    } else if(y[i]==y[j]) {
        if(x[j]>x[i]) return 0; else return M_PI;
    }
    return atan2(y[j]-y[i], x[j]-x[i]);
}

int enc_circle() {
    vector<angle> angles;
    int ans = 1;
    double d, td, tang;
    angle a1, a2;
    for (int i = 0; i < n; i++) {
        angles.clear();
        // get angid points to compare to
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (x[i] == x[j] && y[i] == y[j]) continue;
            d = SQ(x[j] - x[i]) + SQ(y[j] - y[i]);
            if (SQ(2*r) + EPS < d) continue;
            td = sqrt(d);
            // get point relative to pi
            tang = ang(i, j);
            d = acos(td/(2*r));
            // get angle to center of circun
            a1.ang = tang+d+EPS/10;
            a1.p = j;
            a2.ang = tang-d-EPS/10;
            a2.p = j;
            angles.push_back(a1);
            angles.push_back(a2);
        }
        // normalize angles to 0 and 2PI, 0-360
        for (int j = 0; j < angles.size(); j++) {
            while (angles[j].ang < 0) angles[j].ang += 2*M_PI;
            while (angles[j].ang >= 2*M_PI) angles[j].ang -= 2*M_PI;
        }
        sort(angles.begin(), angles.end(), cmpa);
        int cnt = 0;
        // check points that are already in the starting circle
        vector<bool> in; in.resize(n);
        for (int j = 0; j < n; j++) {
            if (SQ(x[j] - (x[i]+r)) + SQ(y[j] - y[i]) <= SQ(r)+EPS) {
                in[j] = 1;
                cnt++;
            } else {
                in[j] = 0;
            }
        }
        // update answer with initial points
        ans = max(ans, cnt);
        for (int j = 0; j < angles.size(); j++) {
            if (in[angles[j].p]) cnt--;
            else cnt++;
            in[angles[j].p] = 1-in[angles[j].p];
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main() {
    while (scanf("%d %d", &n, &r) && (n || r)) {
        for (int i = 0; i < n; i++) scanf("%d %d", &(x[i]), &(y[i]));
        printf("It is possible to cover %d points.\n", enc_circle());
    }
    return 0;
}
