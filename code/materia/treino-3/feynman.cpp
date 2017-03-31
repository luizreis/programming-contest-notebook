#include <cstdio>

int main () {
    int n;
    scanf("%d",&n);
    long long ac;
    reseta:ac=0;
    for(int i = 1; i <= n; i++)
        ac += i*i;
    printf("%lld\n",ac);
    scanf("%d",&n);
    if (n != 0)
        goto reseta;
    return 0;
}
