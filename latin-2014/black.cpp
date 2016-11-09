#include <bits/stdc++.h>
using namespace std;

int a, b, bc, wc;
char str[5001];

int main() {
    while (scanf("%d %d", &a, &b) != EOF) {
        scanf("%s", str);
        bc = 0;
        for(int i=0; str[i]; i++) bc += (str[i] == 'B' ? 1 : 0);

        wc = 0;
        for(int i=0; i<bc; i++) wc += (str[i] == 'W' ? 1 : 0);

        long long val = wc*a;
        long long pe = bc-1, pd = bc;
        while(1){
            while(pe >= 0 && str[pe] != 'W') pe--;
            while(str[pd] && str[pd] != 'B') pd++;

            if(pe < 0 || !str[pd]) break;

            if(a < (pd-pe)*(a-b)) break;

            val += (pd-pe)*(a-b)-a;
            pe--, pd++;
        }

        printf("%lld\n", val);
    }
    return 0;
}

//2 1
//BW WB

//5 3
//WBWWBWBWBW BBBWWBBB
