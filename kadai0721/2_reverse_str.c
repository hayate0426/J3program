#include <stdio.h>
#include <string.h>

#define NUM 100

char* check(char *str, int len){

  if (len == 1){
    printf("%c", str[len-1]);
  }
    else {
      printf("%c", str[len-1]);
      return check(str, len - 1);
    }
       return "\n";
}

int main(){
  char str[NUM];

  printf("Original >> ");
  scanf("%s", &str);

  int len = strlen(str);

  printf("Reverse >> ");
  check(str, len);
}
