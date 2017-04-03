#include <bits/stdc++.h>
using namespace std;

int arr[100100], n, x;
long long c;
map<int, int> f;

int main() {
    c = 0;
    scanf("%d %d", &n, &x);
    for (int i=0; i<n; i++) scanf("%d", arr+i);
    for (int i=0; i<n; i++) {
        int y = x^arr[i];
        if (f.find(y) != f.end()) c+= f[y];
        f[arr[i]]++;
    }
    printf("%lld\n", c);
    return 0;
}
