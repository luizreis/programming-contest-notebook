#include <bits/stdc++.h>
using namespace std;

int trie[1000010][26], f[1000010];
int n, ans;

void dfs(int u, int c) {
    int cc = 0, d;
    for (int i=0; i<26; i++) if (trie[u][i]) cc++;
    d = (cc>1)?1:0 || !u || f[u];
    for (int i=0; i<26; i++) if (trie[u][i]) dfs(trie[u][i], c+d);
    if (f[u]) ans += c;
}

int main() {
    char w[81];
    int v, state;
    while (scanf("%d", &n) != EOF) {
        memset(trie[0], 0, sizeof(trie[0]));
        f[0] = state = ans = 0;
        for (int i=0; i<n; i++) {
            scanf("%s", w);
            v = 0;
            for (int j=0; w[j]; j++) {
                if (!trie[v][w[j]-'a']) {
                    trie[v][w[j]-'a'] = ++state;
                    memset(trie[state], 0, sizeof(trie[state]));
                    f[state] = 0;
                }
                v = trie[v][w[j]-'a'];
            }
            f[v] = 1;
        }
        dfs(0, 0);
        printf("%.2lf\n", ans/(double)n);
    }
    return 0;
}
