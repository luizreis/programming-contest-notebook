#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000100;
const int MAXC = 26;
int trie[MAX][MAXC];
int match[MAX], fail[MAX];
int str[MAX];
char words[10003][1003];
int p[10009], sz[10009], mem[10009];
int n;

void build() {
    // only memset if the state will be used
    memset(trie[0], 0, sizeof(int)*MAXC);
    int state = 0;
    for(int i = 0; i < n; i++) {
        char *s = words[i];
        int v = 0;
        for(int j = 0; s[j]; j++) {
            if(!trie[v][s[j]-'a']) {
                trie[v][s[j]-'a'] = ++state;
                // only memset if the state will be used
                memset(trie[state], 0, sizeof(int)*MAXC);
                match[state] = 0;
            }
            v = trie[v][s[j]-'a'];
        }
        match[v] = 1;
        str[v] = i;
    }
    queue<int> q;
    for(int i = 0; i < MAXC; i++)
        if(trie[0][i])
            q.push(trie[0][i]), fail[trie[0][i]] = 0;
    while(!q.empty()) {
        int stt = q.front(); q.pop();
        for(int i = 0; i < MAXC; i++) {
            if(!trie[stt][i]) continue;
            int &p = fail[trie[stt][i]];
            p = fail[stt];
            while(p && !trie[p][i]) p = fail[p];
            p = trie[p][i];
            if(match[p]) match[trie[stt][i]] |= 2;
            q.push(trie[stt][i]);
        }
    }
}

int pd() {
    int ans = 0;
    // when a word of length l is being calculated, all words of length m
    // with l < m, have been previously calculated
    for(int i = 0; i < n; i++) {
        int k = p[i];
        char *s = words[k]; int m = sz[k];
        int v = 0;
        mem[k] = 1;
        for(int j = 0; j < m; j++) {
            v = trie[v][s[j]-'a'];
            int state = v;
            if(j == m - 1) state = fail[state];
            // track end of words using fail function
            while(match[state]) {
                if(match[state] & 1) mem[k] = max(mem[k], 1 + mem[str[state]]);
                state = fail[state];
            }
        }
        ans = max(ans, mem[k]);
    }
    return ans;
}

int cmp(const int i, const int j) { return sz[i] < sz[j]; }

int main() {
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            sz[i] = strlen(words[i]);
            p[i] = i;
        }
        // sort in order to execute a bottom-up dp
        sort(p, p + n, cmp);
        
        build();
        
        printf("%d\n", pd());
    }
}
