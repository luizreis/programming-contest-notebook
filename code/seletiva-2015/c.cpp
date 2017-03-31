#include <cstdio>
#include <cstdlib>

using namespace std;

#define ABS(x) (x < 0)?(-x):(x)

typedef struct {
  int x, y;
} point;

point vec[100001], temp;

int ccw (point p1, point p2, point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int dist (point p1, point p2) {
  return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int comp (const void *vp1, const void *vp2) {
  point *p1 = (point *)vp1;
  point *p2 = (point *)vp2;

  int o = ccw(vec[1], *p1, *p2);
  if (o == 0) return (dist(vec[1], *p2) >= dist(vec[1], *p1))? -1 : 1;
  return (o > 0)? -1: 1;
}

double area(int m) {
  int sum = 0, sub = 0;
  for (int i = 1; i <= m; i++) {
    sum += (vec[i-1].x * vec[i].y);
    sub += (vec[i-1].y * vec[i].x);
  }
  return ABS((sum-sub)/2.0);
}

int main () {
  int n, miny = 0;

  vec[0] = (point){100000,100000};

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &vec[i].x, &vec[i].y);
    if (vec[miny].y > vec[i].y) miny = i;
  }

  temp = vec[1];
  vec[1] = vec[miny];
  vec[miny] = temp;
  //printf("1: %d %d\nminy: %d %d\n",vec[1].x,vec[1].y,vec[miny].x,vec[miny].y);
  
  // qsort pior caso mto grande. USAR SORT
  qsort(&vec[2], n-1, sizeof(point), comp);

  vec[0] = vec[n];
  //for(int i=0; i <= n; i++)
   // printf("P%d (%d, %d)\n", i, vec[i].x, vec[i].y);

  int m = 1;

  for (int i = 2; i <= n; i++) {
    while (ccw(vec[m-1], vec[m], vec[i]) < 0) {
      if (m > 1) m -= 1;
      else if ( i == n) break;
      else i += 1;
    }
    m++;
    temp = vec[i];
    vec[i] = vec[m];
    vec[m] = temp;
  }
  
 // printf("\n\n");
 // for(int i=0; i <= n; i++)
 //   printf("P%d (%d, %d)\n", i, vec[i].x, vec[i].y);
 // printf("M: %d\n", m);
  printf("%.2lf\n", area(m));

  return 0;
}
