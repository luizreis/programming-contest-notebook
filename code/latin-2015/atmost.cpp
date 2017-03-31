#include <bits/stdc++.h>
using namespace std;

char n[32], s;
long long pot10[32];

long long f(int pos, int m1, int m2){
    if(pos >= s) return 0;

    long long f1, f2;
    f1 = f2 = -1;
    int p = 1<<(n[pos]-'0');
    if(!(m1&p)) f1 = f(pos+1, m1|p, m2);
    else if(!(m2&p)) f1 = f(pos+1, m1, m2|p);

    if(f1 >= 0) f1 += (n[pos]-'0')*pot10[s-pos-1];

    int d;
    for(d = n[pos]-'0'-1; d>=0; d--){
        if(!(m1&(1<<d))){
            f2 = d;
            m1 = m1|(1<<d);
            break;
        }
        if(!(m2&(1<<d))){
            f2 = d;
            m2 = m2|(1<<d);
            break;
        }
    }
    if(d>=0){
        pos++;
        for(int i=9; pos<s && i>=0; i--){
            if(!(m1&(1<<i))){
                f2 = f2*10 + i;
                m1 = m1|(1<<i);
                pos++;
            }
            if(pos>=s) break;

            if(!(m2&(1<<i))){
                f2 = f2*10 + i;
                m2 = m2|(1<<i);
                pos++;
            }
        }
    }
    return max(f1, f2);
}

int main() {
    pot10[0] = 1;
    for(int i=1; i<32; i++)
        pot10[i] = 10*pot10[i-1];

    while(scanf("%s", n) != EOF) {
        s = strlen(n);
        printf("%lld\n", f(0, 0, 0));
    }
    return 0;
}
