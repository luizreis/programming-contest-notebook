#include <cstdio>

using namespace std;

int vis[10010];

int main () {
  int n, tmp;

  scanf("%d", &n);
loop:
  for (int i = 1; i <=n; i++){
    scanf("%d", &vis[i]);
  }
  vis[n+1] = vis[1];
  vis[0] = vis[n];
  tmp = 0;
  for(int i = 1; i <=n; i++){
    if (vis[i-1] > vis[i] && vis[i] < vis[i+1])
      tmp++;
    if (vis[i-1] < vis[i] && vis[i] > vis[i+1])
      tmp++;
  }
  printf("%d\n",tmp);
  scanf("%d", &n);
  if(n != 0)
    goto loop;
  return 0;
}