#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

inline int cmpf(double a, double b) {
	if (fabs(a-b) < EPS) return 0;
	return a < b ? -1 : 1;
}

struct pvec {
	double x, y;
	pvec(double x=0, double y=0) :x(x), y(y) {}
	pvec operator+(pvec p) { return pvec(x+p.x,y+p.y); }
	pvec operator-(pvec p) { return pvec(x-p.x,y-p.y); }
	pvec operator*(double a) { return pvec(a*x,a*y); }
	bool operator==(pvec p) { return cmpf(x,p.x)==0 and cmpf(y,p.y)==0; }
	double dot(pvec p) { return x*p.x + y*p.y; }
	double cross(pvec p) { return x*p.y - y*p.x; } // < 0 se p tá a direita de this
	double abs() { return sqrt(x*x + y*y); }
	double abs2() { return x*x + y*y; }
	double angulo(pvec p) { // angulo entre vetores
				   //[---cos do angulo----]
		return acos( dot(p)/(abs()*p.abs()) );
	}
	bool entre(pvec a, pvec c) { // this ta alinhado entre a e c?
		pvec b = *this;
		return (cmpf( (a-b).cross(c-b),0.0)== 0 and
				cmpf( (a-b).dot(c-b), 0.0) <= 0);
	}
};

// verifica se o segmento (p1-p2) cruza com (s1-s2).
bool cruza(pvec p1, pvec p2, pvec s1, pvec s2) {
	long double tt1 = (p1-s1).cross(s2-s1);
	long double tt2 = (p2-s1).cross(s2-s1);
	// >= 0 se NAO quiser que de true se tocar na borda
	if (cmpf(tt1*tt2,0.0) > 0) return false;
	tt1 = (s2-p1).cross(p2-p1);
	tt2 = (s1-p1).cross(p2-p1);
	// >= 0 se NAO quiser que de true se tocar na borda
	if (cmpf(tt1*tt2,0.0) > 0) return false;
    return true;
}

int t, m, c;
pvec mur[100], cab[50], ini, fim;
vector <pair <int, double> > adj[201];

double calc_dists(pvec a, pvec b){
    for(int i=0; i<m; i++){
        if(a == mur[i<<1] || a == mur[(i<<1)|1] || b == mur[i<<1] || b == mur[(i<<1)|1]) continue;
        if(cruza(a, b, mur[i<<1], mur[(i<<1)|1])) return -1;
    }

    return (a-b).abs();
}

void comp_dists(pvec *va, int ca, int ta, pvec *v1, int c1, int t1){
    for(int i=0; i<ta; i++)
        for(int j=0; j<t1; j++){
            if(va[i] == v1[j]) continue;
            double d = calc_dists(va[i], v1[j]);
            if(d == -1) continue;

            adj[i+ca].push_back(make_pair(j+c1, d));
            adj[j+c1].push_back(make_pair(i+ca, d));
        }
}

double dij(){
    priority_queue <pair <double, pair <int, int> >,vector <pair <double, pair <int, int> > >, greater <pair <double, pair<int, int> > > > fila;
    bool vis[201][51];
    memset(vis, false, sizeof(vis));
    fila.push(make_pair(0, make_pair(199, t)));

    while(!fila.empty()){
        double d = fila.top().first;
        int dest = fila.top().second.first;
        int nt = fila.top().second.second;
        fila.pop();
        if(vis[dest][nt]) continue;
        vis[dest][nt] = true;

        if(dest == 200) return d;

        for(int i=0; i<adj[dest].size(); i++){
            int u = adj[dest][i].first;
            if(100 <= dest && dest <= 150 && 100 <= u && u <= 150 && nt > 0){
                fila.push(make_pair(d, make_pair(u, nt-1)));
            }else{
                fila.push(make_pair(d+adj[dest][i].second, make_pair(u, nt)));
            }
        }
    }
    return 0.0;
}

int main(){
    while(scanf("%d %d %d", &t, &m, &c) != EOF){
        for(int i=0; i<201; i++) adj[i].clear();

        for(int i=0; i<m; i++)
            scanf("%lf %lf %lf %lf", &(mur[i<<1].x), &(mur[i<<1].y), &(mur[(i<<1)|1].x), &(mur[(i<<1)|1].y));
        for(int i=0; i<c; i++)
            scanf("%lf %lf", &(cab[i].x), &(cab[i].y));
        scanf("%lf %lf", &(ini.x), &(ini.y));
        scanf("%lf %lf", &(fim.x), &(fim.y));

        comp_dists(mur, 0, 2*m, mur, 0, 2*m);
        comp_dists(mur, 0, 2*m, cab, 100, c);
        comp_dists(cab, 100, c, cab, 100, c);

        comp_dists(&ini, 199, 1, mur, 0, 2*m);
        comp_dists(&ini, 199, 1, cab, 100, c);

        comp_dists(&fim, 200, 1, mur, 0, 2*m);
        comp_dists(&fim, 200, 1, cab, 100, c);

        comp_dists(&ini, 199, 1, &fim, 200, 1);

        printf("%.1lf\n", dij());
    }

    return 0;
}

