#include <stdio.h>
#include <string.h>

#define NUM 10

int main(int argc, char *argv[]){
  int i,j;
  char index[argc][NUM];

  for (i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  int count[argc];
for (i = 0; i < argc; i++) {
  count[i]=0;
}
<<<<<<< HEAD

  for (i = 0; i <= argc; i++) {

    sprintf(index[i],argv[1],i);
    printf("%s %d\n",index[i],argc);

    j = 0;
      while(j < argc){
        if (strcmp(index[i], argv[j]) == 0) {
           count[i]++;
           sprintf(argv[j],argv[argc-1],j);
           argc--;
      //     printf("%s %d\n",argv[j],argc);
         }

          else if(strcmp(index[i], argv[j]) != 0){
            j++;}
        //    printf("[%s %d]\n",argv[j],argc);
=======
>>>>>>> 5a43f3f4456b0f39eb5ca7556dbb977b6535063d

  for (i = 0; i <= argc; i++) {
    sprintf(index[i],argv[1],i);
    j = 0;
      while(j < argc){
        if (strcmp(index[i], argv[j]) == 0) {
           count[i]++;
           sprintf(argv[j],argv[argc-1],j);
           argc--;
           printf("%s %d\n",argv[j],argc);
         }
          else
            j++;
    }
  }

for (j = 0; j < i; j++) {
  printf("same[%s] = %d\n",index[j],count[j]);
}

  return 0;
}
