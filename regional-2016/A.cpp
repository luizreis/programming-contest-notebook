#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if( a == c || a == b || b == c || a+b == c || a+ c == b || b + c == a)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
