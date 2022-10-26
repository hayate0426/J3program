#include <stdio.h>
#include <string.h>

#define NUM 100

char* juage(char str[]){
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len-(i+1)]) {
      return "NO";
    }
  }
  return "YES";
}

int main (void){
  char str[NUM];
  scanf("%s", &str);
  printf("[%s] = %s\n", str, juage(str));
  return 0;
}
