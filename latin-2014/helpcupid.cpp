#include <bits/stdc++.h>
using namespace std;

int n, v[1010];

int main(){
    while(scanf("%d", &n) != EOF){
        memset(v, 0, sizeof(v));
        for(int i=0; i<n; i++) scanf("%d", v+i);

        int m1, m2;
        m1 = m2 = 0;
        sort(v, v+n);
        for(int i=0; i<n; i+=2) m1 += min(abs(v[i+1] - v[i]), 24-abs(v[i+1] - v[i]));
        for(int i=1; i<n-1; i+=2) m2 += min(abs(v[i+1] - v[i]), 24-abs(v[i+1] - v[i]));
        m2 += min(abs(v[0] - v[n-1]), 24-abs(v[0] - v[n-1]));

        printf("%d\n", min(m1, m2));
    }
    return 0;
}
