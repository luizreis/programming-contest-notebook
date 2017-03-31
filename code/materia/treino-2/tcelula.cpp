#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

#define EPS 1e-12
#define dist(a, b) ((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]))
#define min(a, b) ((a) - (b) < EPS ? (a) : (b))
#define max(a, b) (EPS > (b) - (a) ? (a) : (b))

int n;
int p[40][2], pi[40];
char in[40];

int f[40], tf;

bool cmp(int a, int b){
    if(p[a][0] < p[b][0]) return true;
    if(p[a][0] > p[b][0]) return false;
    return (p[a][1] < p[b][1]);
}

inline int ccw(int a, int b, int c){
    return (p[b][0] - p[a][0])*(p[c][1]-p[a][1]) - (p[b][1] - p[a][1])*(p[c][0] - p[a][0]);
}

inline double cosang(int o, int a, int b){
    return ((p[a][0]-p[o][0])*(p[b][0]-p[o][0]) + (p[a][1]-p[o][1])*(p[b][1]-p[o][1])) / (sqrt(dist(p[o], p[a]))*sqrt(dist(p[o], p[b])));
}

void fc(){
    int tl = 0, tu = 0;
    for(int i=0; i<n; i++){
        if(in[pi[i]]) continue;
        while(tl >= 2 && !(ccw(f[tl-2], f[tl-1], pi[i]) > 0)) tl--;
        f[tl++] = pi[i];
    }
    if(tl) tl--;

    for(int i=n-1; i>=0; i--){
        if(in[pi[i]]) continue;
        while(tu >= 2 && !(ccw(f[tl+tu-2], f[tl+tu-1], pi[i]) > 0)) tu--;
        f[tl+tu++] = pi[i];
    }
    if(tu) tu--;

    tf = tl+tu;

    return;
}

bool circun(int i, int j, int k, double *o){
    double ij[2], ki[2];
    ij[0] = p[i][0]-p[j][0];
    ij[1] = p[i][1]-p[j][1];
    ki[0] = p[k][0]-p[i][0];
    ki[1] = p[k][1]-p[i][1];

    double den = 2*(ij[0]*ki[1] - ij[1]*ki[0]);
    if(!den) return false;

    double aux1, aux2;
    aux1 = ij[1]*(p[j][1]+p[i][1]) + ij[0]*(p[j][0]+p[i][0]);
    aux2 = ki[1]*(p[k][1]+p[i][1]) + ki[0]*(p[k][0]+p[i][0]);

    o[0] = (ki[1]*aux1 - ij[1]*aux2)/den;
    o[1] = (ij[0]*aux2 - ki[0]*aux1)/den;

    return true;
}

double applet(){
    fc();

    if(tf <= 1) return 0;
    if(tf == 2) return dist(p[f[0]], p[f[1]])/4.0;

    int s0 = 0, s1 = 1;

    while(1){
        int v;
        double a = -2, tc; // i.e. a < cosseno do maior angulo possivel
        for(int i=0; i<tf; i++){
            if(i == s0 || i == s1) continue;
            tc = cosang(f[i], f[s0], f[s1]);
            if(tc > a){
                a = tc;
                v = i;
            }
        }
        if(a < EPS){
            return dist(p[f[s0]], p[f[s1]])/4.0;
        }

        double c1 = cosang(f[s0], f[s1], f[v]), c2 = cosang(f[s1], f[v], f[s0]);
        if(c1 > EPS && c2 > EPS){
            double o[2], r;
            circun(f[s0], f[s1], f[v], o);
            return dist(o, p[f[s0]]);
        }

        s0 = (c1 < EPS ? s1 : s0);
        s1 = v;
    }
}
// */

int main(){
    while(scanf("%d", &n) && n){
        for(int i=0; i<n; i++){
            scanf("%d %d", p[i], p[i]+1);
            pi[i] = i;
        }
        sort(pi, pi+n, cmp);

        double m = 1e12;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double o[2], r1, r2;

                o[0] = (p[i][0] + p[j][0])/2.0;
                o[1] = (p[i][1] + p[j][1])/2.0;
                r1 = dist(o, p[i]);

                memset(in, 0, sizeof(in));
                for(int k=0; k<n; k++)
                    in[k] = (dist(p[k], o) < r1);
                in[i] = in[j] = !(0);

                r2 = applet();

                m = min(max(r1, r2), m);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    double o[2], r1, r2;

                    if(!circun(i, j, k, o)) continue;
                    r1 = dist(o, p[i]);

                    memset(in, 0, sizeof(in));
                    for(int l=0; l<n; l++)
                        in[l] = (dist(p[l], o) < r1);
                    in[i] = in[j] = in[k] = !(0);

                    r2 = applet();

                    m = min(max(r1, r2), m);
                }
            }
        }

        printf("%.2lf\n", sqrt(m));
    }
    return 0;
}
