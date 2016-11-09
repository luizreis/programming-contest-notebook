#include <bits/stdc++.h>
using namespace std;

int n, h[100001];
int t[200002], t2[200002];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i){
		t[i] = max(t[i<<1], t[i<<1|1]);
		t2[i] = min(t2[i<<1], t2[i<<1|1]);
	}
}

int querymax(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(res, t[--r]);
	}
	return res;
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0x3f3f3f3f;
	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, t2[l++]);
		if (r&1) res = min(res, t2[--r]);
	}
	return res;
}

int bsl(int a, int b, int i) {
	while (abs(a-b) > 1) {
		int m = (a+b)/2;
		if (querymax(b, b) > h[i]) return b;
		if (querymax(m, b) > h[i]) a = m;
		else b = m;
	}
	return h[b] > h[i] ? b : a;
}

int bsr(int a, int b, int i) {
	while (abs(a-b) > 1) {
		int m = (a+b)/2;
		if (querymax(a, a) > h[i]) return a;
		if (querymax(a, m) > h[i]) b = m;
		else a = m;
	}
	return h[a] > h[i] ? a : b;
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i=0; i<n; i++){
			scanf("%d", h+i);
			t[n+i] = t2[n+i] = h[i];
		}
		build();
		int fl = -1;
		for(int i=1; i<n-1; i++){
			if(h[i-1] < h[i] && h[i+1] < h[i]){
				int mxl = bsl(0, i-1, i), mxr = bsr(i+1, n-1, i);
				int mnl = query(mxl, i), mnr = query(i, mxr);
				if(h[i] - mnl >= 150000 && h[i] - mnr >= 150000){
					if(fl) fl=0, printf("%d", i+1);
					else printf(" %d", i+1);
				}
			}
		}
		printf("\n");
	}

	return 0;
}
