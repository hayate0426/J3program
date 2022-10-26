#include <stdio.h>

#define NUM 100
#define count 2

int main() {
int n = 0 , j = 0 , check = 0;
char str[count][NUM];

for (int i = 0; i < count; i++) {
  scanf("%s", str[i]);
}

while (str[1][j] != '\0') {
  if (str[0][n] != str[1][j]) {
    printf("%c %c NG\n", str[0][n], str[1][j]);
    n++;
    check++;
    j=0;
  }
    else{
      printf("%c %c OK\n", str[0][n], str[1][j]);
      n++;
      j++;
      check++;
    }
  }
  printf("%d\n", check);

  return 0;
}
