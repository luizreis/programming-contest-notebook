#include <bits/stdc++.h>

using namespace std;

stack<int> as,aq;
int a[1001],b[1001];
int ab[1001];

int n,tmp;

int main(){
ants:
    while(scanf("%d",&n) && n){
        while(scanf("%d",b) && b[0]){
            while(!as.empty()) as.pop();
            while(!aq.empty()) aq.pop();
            for(int i = 1; i < n; i++){
                scanf("%d", b+i);
            }

            for(int i = 0; i < n; i++)
                a[n - i -1] = i + 1;
            memset(ab, 0, sizeof(ab));

            for (int i =0; i < n; i++)
                as.push(a[i]);

            for(int i = 0; i < n ; i++){
                if(ab[b[i]] == 0){
                    while(as.top() != b[i]){
                        tmp = as.top();
                        as.pop();
                        ab[tmp] = 1;
                        aq.push(tmp);
                    }
                    tmp = as.top();
                    as.pop();
                    ab[tmp] = 1;
                } else {
                    if( aq.top() != b[i]){
                        i = n+1;
                    } else {
                        aq.pop();
                    }
                }
            }
            if(as.empty() && aq.empty()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }

    return 0;
}


