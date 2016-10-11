#include <bits/stdc++.h>
using namespace std;

int siev[1000000];
vector<int> p;

int main() {
    int n;
    memset(siev, -1, sizeof(siev));
    for (int i=2; i<=1000000; i++)
        if (siev[i])
            for (int j = i+i; j <= 1000000; j+=i) siev[j] = 0;
    for (int i = 2; i <=1000000; i++)
        if (siev[i]) p.push_back(i);
    while (scanf("%d", &n) && n) {
        int c = 0;
        for (int i = 0; i<p.size(); i++)
            if (!(n%p[i])) c++;
        printf("%d : %d\n", n, c);
    }
}
