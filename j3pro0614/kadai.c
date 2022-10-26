#include <stdio.h>
#include <string.h>

#define NUM 10

int main(int argc, char *argv[]){
  int i,j,b,k=0;
  char index[argc][NUM];
  int map[argc];

  for (i = 1; i < argc ; i++) {
    sprintf(index[i],argv[i],i);
    for (b = 1; b <= i ; b++) {
      if (strcmp(index[i], index[b]) == 0 && !(b==i)) {
        map[b]=1;
      }
       else{
         map[i]=0;
       }
    }
  }

  for (i = 1; i < argc; i++) {
    if (map[i]==1) {
      continue;
    }
    
      for (j = 1; j < argc ; j++) {
        if (strcmp(index[i], argv[j]) == 0) {
         k++;
       }
    }
    printf("[%s] = %d\n",index[i],k);

    k=0;
  }

  return 0;
}
