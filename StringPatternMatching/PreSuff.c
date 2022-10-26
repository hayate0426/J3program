#include<stdio.h>

#define NUM 10

int main() {
  int i = 0;
  char argv[NUM];

  scanf("%s", argv);
while (argv[i] != '\0' ) {
  printf("%c\n", argv[i]);
  i++;
}

int count = i;
char Prefix[count][NUM], Suffix[count][NUM];

printf("%d\n",count );

for (int j = 0; j < count; j++) {
  for (int k = 0; argv[k] != '\0'; k++) {
    Prefix[j][k] = argv[0];
    Suffix[j][k] = argv[k];
    printf(" %c ", Prefix[j][k]);
    printf(" %c ", Suffix[j][k]);
  }
  printf("\n");
}
  return 0;
}
