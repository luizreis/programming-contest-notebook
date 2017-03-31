#include <bits/stdc++.h>
using namespace std;

int w, d, a, k;
int p[4][9];

double vp(double x, double d){
  double a[4] = {0, 0, 0, 0};
  for(int i=0; i<4; i++)
  for(int j=k; j>=0; j--)
    a[i] = a[i]*x + p[i][j];

  if(a[0]/a[1] < -d) return 0;
  return (a[0]/a[1])-max((a[2]/a[3]), -d);
}

double itgl(double d){
  double inc = w/1e5;
  double ar = 0;
  for(double x=0; x<w; x+=inc)
    ar += (vp(x, d)+vp(x+inc, d))*inc/2.0;
  return ar;
}


#define N 1500
inline double simpson(double a, double b, double d){
  double h = (b-a)/N;
  double h2 = h/2;
  double h6 = h/6;
  double x = a;
  double nx = x + h;
  double res = 0;

  for(int i = 0; i < N; i++){
    nx = x + h;
    res += h6*(vp(x, d)+4*vp(x+h2, d)+vp(nx, d));
    x = nx;
  }
  return res;
}

int main(){
  while(scanf("%d %d %d %d", &w, &d, &a, &k) != EOF){
    for(int i=0; i<4; i++)
    for(int j=0; j<=k; j++)
      scanf("%d", p[i]+j);

    double i = 0, j = d;
    for(int k=0; k<30; k++){
      double m = (i+j)/2;

      if(simpson(0, w, m) < a) i = m;
      else j = m;
    }

    printf("%.5lf\n", (i+j)/2);
  }

  return 0;
}
