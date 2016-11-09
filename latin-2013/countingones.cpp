#include <bits/stdc++.h>
using namespace std;

long long unsigned v[63], a, b;

long long unsigned S(long long unsigned n){
	if(!n) return 0;
	if((1LL<<((sizeof(long long)<<3) - __builtin_clzll(n)))-1 == n)
		return v[(sizeof(long long)<<3) - __builtin_clzll(n)];
	return v[(sizeof(long long)<<3) - __builtin_clzll(n)-1] + S(n^(1LL<<((sizeof(long long))<<3) - __builtin_clzll(n)-1)) + n - ((1LL << ((sizeof(long long)<<3) - __builtin_clzll(n)-1))-1);
}

int main(){
	v[0] = 0;
	for(int i=1; i<63; i++)
		v[i] = (v[i-1]<<1) + (1LL<<(i-1));
	while(scanf("%llu %llu", &a, &b) != EOF)
		printf("%llu\n", S(b)-S(a-1));

	return 0;
}
