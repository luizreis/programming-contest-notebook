#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n, v[1001][2];
long long s, ig, x, y, ult;
multiset<long long> cj;

int main(){
  while(scanf("%d", &n) && n){
    for(int i=0; i<n; i++)
      scanf("%d %d", &(v[i][0]), &(v[i][1]));

    s=0;
    for(int i=0; i<n; i++){
      cj.clear();
      for(int j=0; j<n; j++){
        if(j != i){
          x = v[i][0]-v[j][0];
          y = v[i][1]-v[j][1];
          cj.insert(x*x + y*y);
        }
      }

      ig=1;
      ult = *(cj.begin());
      multiset<long long>::iterator it=cj.begin();
      for(it++; it!=cj.end(); it++){
        if(*it == ult){
          ig++;
        }else{
          ult = *it;
          s += (ig*(ig-1))/2;
          ig=1;
        }
      }
      s += (ig*(ig-1))/2;
    }
    printf("%lld\n", s);
  }
  return 0;
}