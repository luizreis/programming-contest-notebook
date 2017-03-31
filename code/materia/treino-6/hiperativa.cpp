#include <bits/stdc++.h>
using namespace std;

#define MOD 100000000

int n, m;
pair<int, int> t[101];
int mem[101][101];

int dp(int prev, int pos) {
    if(t[pos].second == m) return 1;
    if (mem[prev][pos] != -1) return mem[prev][pos];
    int c = 0;
    for(int i = pos+1; i < n; i++){
        if(t[i].first > t[pos].first && t[i].first <= t[pos].second && t[i].second > t[pos].second && (prev == pos || t[i].first > t[prev].second))
            c = (c +dp(pos, i))%MOD;
    }
    mem[prev][pos] = c;
    return c;
}

int main() {
    while (scanf("%d %d", &m, &n) && (m || n)) {
        for(int i = 0;i < n; i++) scanf("%d %d",&t[i].first,&t[i].second);
        sort(t, t+n);
        memset(mem, -1, sizeof(mem));
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(t[i].first == 0) ans = (ans + dp(i,i))%MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}

