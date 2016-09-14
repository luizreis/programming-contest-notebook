#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define MAX(a, b) (((a)>(b))?(a):(b))

using namespace std;

vector<int> adj[1001];
int candidates[1001], vis[1001], depth[1001], p[1001], N, D;

int altura (int v, int d) {
	int h = d;
	if (d > depth[v]) {
		depth[v] = d;
		for (int i = 0; i < adj[v].size(); i++) {
			h = MAX(h, altura (adj[v][i], d+1));
		}
		return h;
	}
	return 0;
}

int ciclo (int v, int u, int d) {
	if (!vis[v]) {
		depth[v] = d;
		vis[v] = 1;
		p[v] = u;
		for (int i = 0; i < adj[v].size(); i++) {
			if (!ciclo(adj[v][i], v, d+1)) return 0;
		}
		return 1;
	} else {
		if (depth[u] >= depth[v]) return 0;
	}
}

int main () {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int m;
		scanf("%d", &m);
		if (m == 0) candidates[i] = 1;
		for (int j = 0; j < m; j++) {
			int mi;
			scanf("%d", &mi);
			adj[mi].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			memset(vis, 0, sizeof(vis));
			if (!ciclo(i, 0, 1)) {
				printf("-1\n");
				return 0;
			}
		}
	}
	D = 0;
	memset(depth, 0, sizeof depth);
	for (int i = 1; i <= N; i++) {
		altura(i, 1);
	}
	for (int i = 1; i <= N; i++) {
		D = MAX(D, depth[i]);
	}
	printf("%d\n", D);
	return 0;
}
