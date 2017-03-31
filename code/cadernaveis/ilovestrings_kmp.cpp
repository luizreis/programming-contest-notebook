#include <bits/stdc++.h>
using namespace std;

char s[100010], w[1001];
int k, q, t[1001];

void build(char *w) {
    int pos = 2, cnd = 0;
    int sz = strlen(w);
    t[0] = -1; t[1] = 0;
    while(pos < sz) {
        if (w[pos-1] == w[cnd]) t[pos++] = ++cnd;
        else if (cnd > 0) cnd = t[cnd];
        else t[pos++] = 0;
    }
}

int kmp(char *w, char *s) {
    int m = 0, i = 0;
    int sz = strlen(s);
    int szt = strlen(w);
    while (m+i < sz) {
        if (w[i] == s[m+i]) {
            if (i++ == szt-1) return m;
        } else {
            if (t[i] > -1) m = m+i-t[i], i = t[i];
            else m = m+1, i = 0;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &k);
    while (k--) {
        scanf("%s", s);
        scanf("%d", &q);
        while (q--) {
            scanf("%s", w);
            build(w);
            printf("%c\n", (kmp(w, s) != -1)?'y':'n');
        }
    }
}
