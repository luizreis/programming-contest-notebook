#include <cstdio>

using namespace std;


int main(){
  long long int n, b,i;
  long long int dist;
  bool flag=false;
  long long int quad,posx,posy;
  long long int inicio, meio, fim;
  scanf("%lld %lld",&n, &b);
  if (b == 1 && n == 1){
    posy =1;
    posx =1;
    goto imprime;
  }
  /*
  dist=4*(n-1) +1;
  for (i=1; dist <= b; i++){
    b = b - dist;
    n = n - 2;
    dist=4*(n-1);
    flag=true;
  }*/
  inicio = 0;
  fim = n;
  meio = (inicio + fim)/2;
  dist =4*n*meio - 4*meio*meio; 
  if(n % 2)
    if(b == n*n){
      posx = n/2 +1;
      posy = n/2 +1;
     goto imprime;
    }
  //printf("%lld %lld %lld\n",b, n,dist);
  while (1){
    if(b- dist > 0 && b - dist < 4*(n - 2*meio -1))
      goto out;

    if(b-dist == 0)
      goto out;

    if(b - dist < 0){
      fim = meio;
      meio = (inicio+fim)/2;
      dist = 4*n*meio - 4*meio*meio;
    }else if(b - dist > 0){
      inicio = meio;
      meio = (inicio+fim)/2;
      dist = 4*n*meio - 4*meio*meio;
    }
  }
  out:
 // printf("meio %lld, meioarea %lld\n",meio,4*n*meio - 4*meio*meio);


  b = b - dist;
  if(b == 0){
    posx = meio;
    posy = meio+1;
    goto imprime;
  }
  n = n - 2*meio;
  i = meio+1;
  b--;

  quad = b / (n-1);
  if (quad == 0){
    posy = i;
    posx = i+(b%(n-1));
  }
  if (quad == 1){
    posy = i+(b%(n-1));
    posx = i+n-1;
  }
  if (quad == 2) {
    posy =(i + n -1);
    posx =(i + n -1) - (b % (n-1));
  }
  if (quad == 3){
    posy = (i + n -1) - (b% (n-1));
    posx = i;
  }
  imprime:
  printf("%lld %lld\n",posy,posx);
   
 return 0;
}
 
