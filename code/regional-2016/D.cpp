#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
set <int> S;

int main(){
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int men = 0x3f3f3f3f;
    for(int i=1; i<=((c/i) + 1); i++){
        if(!(c%i)){
            S.insert(i);
            S.insert(c/i);
        }
    }

    for(set<int>::iterator it=S.begin(); it!=S.end(); it++){
        if(!(*it % a) && (*it % b) && (d % *it)){
            printf("%d\n", *it);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
