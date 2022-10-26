#include <stdio.h>
#include <string.h>

int check(int num){

  if (!(num/2)){
    printf("%d", num);
  }
    else {
      num=num/2;
      printf("%2d ", num);
      return check(num);
    }
      printf("\n");
       return 0;
}

int main(){

  int num;
  printf("Original >> ");
  scanf("%d", &num);

  printf("Reverse >> ");
  check(num);
}
