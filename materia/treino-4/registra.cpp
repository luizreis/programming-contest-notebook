#include <bits/stdc++.h>

using namespace std;

#define STEP 65536

typedef unsigned int uint;

uint trans[32][32], aux[32][32];

inline uint skip(uint state, uint n) {
    uint st[32], nst[32], nstate = 0;
    memset(st, 0, sizeof(st));
    memset(nst, 0, sizeof(nst));
    // convert state to array
    for (int i = 0; i < n; i++) {
        st[i] = (state>>(n-i-1))&1ll;
    }
    // multiply
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            nst[i] = (nst[i] + trans[i][j]*st[j])%2;
        }
    }
    // convert array to state
    for (int i = 0; i < n; i++) {
        nstate |= (nst[n-1-i]%2)<<i;
    }
    return nstate;
}

inline uint next(uint state, uint t, uint qt_bits) {
    uint bit = (__builtin_popcount(state & t) % 2);
    return ((bit << (qt_bits - 1ll)) | (state >> 1ll)) & ((1ll << qt_bits) - 1);
}

int main() {
    uint n, t, ini, end, mask, state;
    uint bit;
    long long s = 0;

    while (scanf ("%d %d", &n, &t) && (n || t)) {
        map<uint, uint> iini, iend;
        memset(trans, 0, sizeof(trans));
        s = STEP;
        mask = 0; // 1 on xor position
        for (int i = 0; i < t; ++i) {
            scanf ("%d", &bit);
            mask |= (1ll << bit);
            trans[0][n-bit-1] = 1;
        }

        scanf ("%x %x", &ini, &end);

        // init interval
        state = ini;
        for (int i = 0; i < STEP ; ++i) {
            if (state == end) {
                printf("%d\n", i);
                goto fim;
            }
            if (iini.find(state) != iini.end()) break;
            iini[state] = 1;
            state = next(state, mask, n);
        }
        // end interval
        state = end;
        for (int i = 0; i < STEP ; ++i) {
            if (iend.find(state) != iend.end()) break;
            iend[state] = i;
            state = next(state, mask, n);
        }
        // init trans
        for (int i = 1; i < n; i++) {
            trans[i][i-1] = 1;
        }
        // print trans
        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%lld", trans[i][j]);
            }
            printf("\n");
        }*/
        // precompute trans^step
        for (int x = 0; x < 16; x++) {
            // trans = trans*trans
            memset(aux, 0, sizeof(aux));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k=0; k < n; k++) {
                        aux[i][j] += trans[i][k]*trans[k][j];
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    trans[i][j] = aux[i][j]%2;
                }
            }
        }

        // start search k-steps at a time
        state = skip(ini, n);
        while (1) {
            if (iend.find(state) != iend.end()) {
                printf("%lld\n", s - iend[state]);
                break;
            } else if (iini.find(state) != iini.end()) {
                printf("*\n");
                break;
            }
            state = skip(state, n);
            s += STEP;
        }
        fim: s++;
    }

    return 0;
}
