#include <cstdio>

using namespace std;

int main(){
  int a, b;
  int com = 0, fim;
  char string[1000];
  char inc = 'N', temp;
  scanf("%s", string);
  
  while (string[com] != '\0') {
    if (string[com] == 'R') inc = 'R';
    else if (string[com] == 'L') inc = 'L';
    else if (string[com] == 'J') inc = 'J';
    com++;
  }

  if (inc == 'R') {
    sscanf(string, "%c%c%d%c%d", &temp, &temp, &a, &temp, &b);
    printf("%d\n", b-a);
  }
  else if (inc == 'L') {
    sscanf(string, "%d%c%c%c%d", &a, &temp, &temp, &temp, &b);
    printf("%d\n", b-a);
  }
  else if (inc == 'J') {
    sscanf(string, "%d%c%d%c%c", &a, &temp, &b, &temp, &temp);
    printf("%d\n", a + b);
  }

  
  
  return 0;
}
