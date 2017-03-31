// sum modification, min query
// query open at right [)
// update open at right [)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n; // array size
int t[N<<1];
int h; // tree height
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

int main() {
    memset(d, 0, sizeof(d));
    // MUST scan array size to n!!!
    h = sizeof(int) * 8 - __builtin_clz(n);

    // input MUST be stored at n+i position
    // e.g. i-eth element is stored at t[i+n]

    // after scan call build
    for (int i=0; i<n; i++) build(i+n);

    return 0;
}
