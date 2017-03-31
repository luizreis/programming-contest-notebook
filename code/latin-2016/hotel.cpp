#include <bits/stdc++.h>
using namespace std;

const int N = 100010;  // limit for array size
int n;  // array size
int t[2 * N];
int h;
int d[N];

void apply(int p, int value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build(int p) {
	while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
  	for (int s = h; s > 0; --s) {
    	int i = p >> s;
    	if (d[i] != 0) {
      		apply(i<<1, d[i]);
      		apply(i<<1|1, d[i]);
      		d[i] = 0;
    	}
  	}
}

void update(int l, int r, int value) {
  	l += n, r += n;
  	int l0 = l, r0 = r;
  	for (; l < r; l >>= 1, r >>= 1) {
    	if (l&1) apply(l++, value);
    	if (r&1) apply(--r, value);
  	}
  	build(l0);
  	build(r0 - 1);
}

int query(int l, int r) {
  	l += n, r += n;
  	push(l);
  	push(r - 1);
  	int res = 0x3f3f3f3f;
  	for (; l < r; l >>= 1, r >>= 1) {
    	if (l&1) res = min(res, t[l++]);
    	if (r&1) res = min(t[--r], res);
  	}
  	return res;
}

int k, tmp, ct = 0;
pair<int, int> p[100010];

int main() {
    scanf("%d %d", &n, &k);
    h = sizeof(int) * 8 - __builtin_clz(n);
    memset(d, 0, sizeof(d));
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        p[i] = make_pair(tmp, i);
        t[i+n] = i;
        ct += tmp;
    }
    for (int i=0; i<n; i++) build(i+n);
    sort(p, p+n);
    for (int i=n-1; i>=0; i--) {
        int nc = query(p[i].second, n);
        if (nc >= k) {
            ct -= p[i].first;
            update(p[i].second, n, -(k+1));
        }
    }
    printf("%d\n", ct);
    return 0;
}
