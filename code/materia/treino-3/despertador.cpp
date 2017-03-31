#include <cstdio>

int main(){
    int h1, h2, m1, m2;
    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 || h2 || m1 || m2)){
        int t1 = h1*60+m1, t2 = h2*60+m2;
        if(t2 >= t1) printf("%d\n", t2-t1);
        else printf("%d\n", t2+1440-t1);

    }
    return 0;
}
