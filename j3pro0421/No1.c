#include<stdio.h>
int main(void)
{
int i,j,c=0,b=0;

for (i = 0; i < 5; i++) {
  for (j = 0; j < i+1; j++) {
    c=c+j;
    printf("%2d",c);
  }
  printf("\n");
  c=0;
}

  return 0;
}
