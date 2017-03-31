#include <cstdio>

using namespace std;

int main () {
	int N, I, c = 0;
	scanf("%d %d", &N, &I);
	for (int k = 0; k < N; k++) {
		int i, j;
		scanf("%d %d", &i, &j);
		if (i == I && j == 0) c++;
	}
	printf("%d\n", c);
}

