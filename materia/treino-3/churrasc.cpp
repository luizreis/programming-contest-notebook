#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

int n, k, v[100010];
deque <pair <int, int> > dq;

int main(){
    while(scanf("%d %d", &n, &k) && (n||k)){
        for(int i=1; i<=n; i++) scanf("%d", v+i);

        dq.clear();
        for(int i=1; i<=k; i++) dq.push_back(make_pair(v[i], i));
        sort(dq.begin(), dq.end());

        printf("%d", dq.front().first);
        for(int i=k+1; i<=n; i++){
            while(!dq.empty() && dq.back().first >= v[i]) dq.pop_back();
            dq.push_back(make_pair(v[i], i));
            while(dq.front().second <= i-k) dq.pop_front();
            
            printf(" %d", dq.front().first);
        }
        printf("\n");
    }
    return 0;
}
