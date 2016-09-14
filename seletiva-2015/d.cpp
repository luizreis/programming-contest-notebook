#include <cstdio>

using namespace std;

int main(){
  int n, t, d;
  float rec = 0;
  scanf("%d", &n);
  for (int i=1; i <= n; i++) {
    scanf("%d %d", &t, &d);
    if (float(d)/t > rec) {
      rec = float(d)/t;
      printf("%d\n", i);
    }
  }
  return 0;
}
