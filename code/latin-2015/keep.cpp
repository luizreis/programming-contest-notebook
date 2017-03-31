#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define MAXN 100010
const long long INF = 0x3f3f3f3f;

typedef pair<long long, pair<long long, long long> > piii;

long long e[MAXN];
piii s[MAXN];
long long n, m, x, y, z, ans, res;

const long long N = MAXN;  // limit for array size
long long t[2 * N];

void build() {  // build the tree
    for (long long i = m - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(long long p, long long value) {  // set value at position p
    for (t[p += m] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

long long query(long long l, long long r) {  // sum on interval [l, r)
    long long res = INF;
    for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(res, t[--r]);
    }
    return res;
}

bool cmp(piii i, piii j) {
    long long a = e[i.first] + i.second.first;
    long long b = e[j.first];
    return a < b;
}

int main() {
    while (scanf("%lld %lld", &n, &m) != EOF) {
        e[1] = 0;
        for (long long i=1; i<=n; i++) {
            scanf("%lld", &x);
            e[i+1] = e[i] + x;
        }
        for (long long i=0; i<m; i++) {
            long long a, c;
            long long b;
            scanf("%lld %lld %lld", &a, &b, &c);
            s[i] = mp(a, mp(b, c));
        }
        sort(s, s+m);
		for (long long i=0; i<m; i++) t[i+m] = INF;
		build();
        res = INF;
        for (long long i=m-1; i>=0; i--) {
			long long costi = INF;
			if (e[s[i].first] + s[i].second.first >= e[n+1]) costi = s[i].second.second;
            long long j = upper_bound(s+i, s+m, s[i], cmp) - s;
            long long costj = INF;
            if (j <= m) costj = query(i, j) + s[i].second.second;
            ans = min(costi, costj);
            if (s[i].first == 1) res = min(res, ans);
			modify(i, ans);
        }
        printf("%lld\n", (res == INF)?-1:res);
    }
    return 0;
}
