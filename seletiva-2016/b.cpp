#include <cstdio>

using namespace std;

int leo[101][101], marc[101][101];

int main () {
	int N, M, L, cm, cl, A;
	scanf("%d", &N);
	scanf("%d %d", &M, &L);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &marc[i][j]);
		}
	}
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &leo[i][j]);
		}
	}
	scanf("%d %d", &cm, &cl);
	scanf("%d", &A);
	if (marc[cm][A] > leo[cl][A]) printf("Marcos\n");
	else if (marc[cm][A] < leo[cl][A]) printf("Leonardo\n");
	else printf("Empate\n");
	return 0;
}
