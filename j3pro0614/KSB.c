#include <stdio.h>
#include <string.h>

typedef struct{
  char *word;
  int count;
}array;

int main(int argc,char *argv[]){
  int i,j;
  array moji[argc];
  int flag;

  i=0;
  while(i<argc){
    moji[i].count=0;
    i++;
  }

  j=0;
  while(j<=argc){
    moji[j].word=argv[1];
    i=0;
    while(i<argc){
      if(strcmp(moji[j].word,argv[i])==0){
      moji[j].count++;
      argv[i]=argv[argc-1];
      argc--;
    }
      else
	i++;
    }
    j++;
  }

  i=0;
  while(i<j){
    printf("%s %d\n",moji[i].word,moji[i].count);
    i++;
  }

  return 0;
}
