#include <bits/stdc++.h>

char s[51], v[51];

int main(){
    scanf("%s", s);
    int tv = 0;
    for(int i=0; s[i]; i++){
        switch(s[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                v[tv++] = s[i];
                break;
        }
    }

    char ok = -1;
    for(int i=0; i<tv; i++)
        ok = (ok && (v[i] == v[tv-i-1]));

    printf("%s\n", ok ? "S" : "N");
    return 0;
}
