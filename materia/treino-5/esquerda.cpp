#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char dir[] = {'N', 'L', 'S', 'O'};
    while (scanf("%d", &n) && n) {
        char string[1010];
        int lado = 0;
        scanf("%s", string);
        for (int i = 0; i < strlen(string); i++)
            if (string[i] == 'D') lado = (lado+1)%4;
            else lado = (lado+3)%4;
        printf("%c\n", dir[lado]);
    }
    return 0;
}
