#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int N;
	vector<int> in;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		in.push_back(a);
	}
	sort(in.begin(), in.end());
	printf("%d %d\n", N/2, in[N/2]-in[N/2-1]);
	return 0;
}
