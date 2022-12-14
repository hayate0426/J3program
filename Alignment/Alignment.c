#include <stdio.h>
#include <string.h>

#define NUM 10

int main(int argc, char const *argv[]) {
  int hoge[NUM][NUM];
  int x,y;
  char String[10];
  printf("Please String(X,Y)\n");
  scanf("%s", &String);
  x = strlen(String);
  scanf("%s", &String);
  y = strlen(String);
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      hoge[i][j]=0;
      printf("%d",hoge[i][j] );
    }
    printf("\n" );
  }

  return 0;
}
