#include <stdio.h>

#define NUM 5

int main(void){
int i,j,count;
int mtr[NUM];
char len[2][NUM+1];
char index[5][5+1];
for (i = 0; i < 2; i++) {
scanf("%s",&len[i] );
 }
 for (j = 0; j < 2; j++) {
   for (count = 0; len[j][count]!='\0'; ++count){
     index[j][count] = len[j][count];
   }
   mtr[j] = count;

   for (i = 0; i < mtr[j]; i++) {
     printf("%c",index[j][i] );
   }
   printf("\n");
}

printf("%d \n",mtr[0]);
printf("%d \n",mtr[1]);


   return 0;
}
