#include <stdio.h>
#include <stdlib.h>

#define NUM 25

int main(){
  char str[NUM]="Tokyo Chiba Saitama";
  int count_space=0,count=0;
  int i,j=0,k=0;
  for (i = 0; str[i]!='\0'; i++) {
  if (str[i]==' ') {
    count_space++;}
    count++;

  }

  char len[count_space+1][NUM];

  for (i = 0; i < count; i++) {
    len[j][k]=str[i];
    k++;

    if (str[i]==' ') {
      j++;
      k=0;
    }
}

for (i = 0; i < count_space+1; i++) {
  printf("%s\n",len[i]);
}

printf("%d %d\n",count, count_space );

  return 0;
}
