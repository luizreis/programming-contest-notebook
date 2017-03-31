#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define SQ(a) ((a)*(a))
#define pb push_back

int cmp(double a, double b=0) { return a < b-EPS? -1 : a > b+EPS? 1 : 0; }

struct point {
    double x, y;
    point(double x, double y): x(x), y(y) {}
    point() {}
    point operator+(const point &p) const { return point(x + p.x, y + p.y); }
	point operator-(const point &p) const { return point(x - p.x, y - p.y); }
	point operator*(double t) const { return point(x*t, y*t); }
	point operator/(double t) const { return point(x/t, y/t); }
	double operator*(const point &p) const { return x*p.x + y*p.y; }
	double operator%(const point &p) const { return x*p.y - y*p.x; }
	double dist() const { return x*x + y*y; }
};

point O, W;

struct event {
    point p;
    int z;
    event(const point &p, int z): p(p), z(z) {}
    event() {}
};

struct segment {
    point u, v;
    segment(const point &u, const point &v): u(u), v(v) {}
    segment() {}
    bool operator<(const segment &s) const { return dist() < s.dist(); }
    double dist() const {
		double den = (u-v)%(W-O);
		if (cmp(den)==0) return -1e-20;
		double t = (u-O)%(W-O) / den; // t = u+(v-u)t-O paralelo a (W-O)
		if (cmp(t,0)<0 || cmp(t,1) > 0) return -1e-20;
		point p = (u-O) + (v-u)*t;
		if ( p*(W-O) < 0) return -1e-20;
		return p.dist();
	}
};

int above(point p) {
	if (p.y == O.y) return p.x > O.x;
	return p.y > O.y;
}

bool circular_order(point p, point q) {
	int tmp = above(q) - above(p);
	if (tmp!=0) return tmp > 0;
	return (p-O)%(q-O) > 0;
}

bool event_order(event P, event Q) {
	return circular_order(P.p, Q.p);
}

int sc, ks, wc;
point k[10010];
segment w[10010];

int count(int sk) {
    vector<event> ev;
    set<segment> sg;
    O = k[sk];
    int ans = 0;
    for (int i=0; i<ks; i++) if (sk != i) ev.pb(event(k[i], -1));
    for (int i=0; i<wc; i++) {
        double cr = (w[i].u - O)%(w[i].v - O); // cross vai dar quem "vem antes"
        if (cr < 0) swap(w[i].u, w[i].v); // troca ptos se necessario
        ev.pb(event(w[i].u, (i<<1)));
        ev.pb(event(w[i].v, (i<<1)+1));
    }
    sort(ev.begin(), ev.end(), event_order);
    W = ev[0].p;
    for (int i=0; i<wc; i++) if (w[i].dist() > 0) {
        sg.insert(w[i]); // coloca muros ativos
    }
    for (int i=0; i<ev.size(); i++) {
        W = ev[i].p;
        int z = ev[i].z;
        if (z<0) {
            if (sg.empty()) { ans++; continue; } // sem muros ativos nesse angulo
            segment fs = *sg.begin(); // muro mais perto de sk para o evento atual
            if (fs.dist() > (ev[i].p-O).dist()) ans++; // kid (w-o) esta mais perto que o 1o muro
        } else if (z&1) sg.erase(w[z>>1]);
        else sg.insert(w[z>>1]);
    }
    return ans;
}

int main() {
    while (scanf("%d %d %d", &sc, &ks, &wc) != EOF) {
        for (int i=0; i<ks; i++) scanf("%lf %lf", &(k[i].x), &(k[i].y));
        for (int i=0; i<wc; i++) {
            point u, v;
            scanf("%lf %lf %lf %lf", &(u.x), &(u.y), &(v.x), &(v.y));
            w[i] = segment(u, v);
        }
        for (int i=0; i<sc; i++) {
            printf("%d\n", count(i));
        }
    }
    return 0;
}
