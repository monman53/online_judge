#include <stdio.h>

int euc(int m, int n){
  return 1 + ((m%n) ? euc(n,m%n) : 0);
}

int main(){
  int i;
  for(i=1;i<=9;i++){
    printf("%d\n",euc(9,i));
  }
  return 0;
}
