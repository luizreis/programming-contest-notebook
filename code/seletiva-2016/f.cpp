#include <cstdio>
#include <cstring>

#define MAX(a, b) (((a)<(b))?(b):(a))

int N, K;
int P[1001], C[1001];

double memo[1001][1001];
bool calc[1001][1001];

double pd (int qst, int pul) {
    if (qst >= N) return 0.0;
    if (!calc[qst][pul]) {
        double n_pula = (C[qst]/100.0)*(P[qst] + pd(qst+1, pul));
        double pula = 0.0;
        if (pul > 0) pula = (P[qst] + pd(qst+1, pul-1));
        memo[qst][pul] = MAX(pula, n_pula);
        calc[qst][pul] = 1;
        return memo[qst][pul];
    } 
    return memo[qst][pul];
}

int main () {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
	}
    memset(calc, 0, sizeof(calc));
	printf("%.2lf\n", pd(0, K));
	return 0;
}
