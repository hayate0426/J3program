#include <stdio.h>
#include <string.h>

#define NUM 100

int check(char *str, int len_first, int len_last){

  if (len_first - len_last == 1 || len_first == len_last){
    return 1;
  }
    else if(str[len_first] == str[len_last]){
      return check(str, len_first + 1, len_last - 1);
    }
       return 0;
}

int main(){

  char str[NUM];
  scanf("%s", &str);
  int len = strlen(str);
  int len_first = 0;
  int len_last = len - 1;

if (check(str, len_first, len_last)==1) {
  printf("yes\n");
}
else
  printf("no\n" );
  return 0;
}
