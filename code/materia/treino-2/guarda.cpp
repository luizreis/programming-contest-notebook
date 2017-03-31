#include <cstdio>

long long d, vf, vg;

int main(){
      while(scanf("%lld %lld %lld", &d, &vf, &vg) != EOF)
          printf("%c\n", (vg*vg*144 >= vf*vf*(d*d+144)) ? 'S' : 'N');
          return 0;
}