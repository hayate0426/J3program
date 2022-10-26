#include <stdio.h>

#define N 10

int flag[N],L[N];

void check(int i, int flag[], int L[], int X) {
  int I = X % 10;
  int j = 0;
  if ((I + 0) < N) j = I + 0;
  if ((I + 0) >= N) j = (I + 0) - N;
   if (L[j] == 0) {
     L[j] = X;
     return;
   }
      else if(L[j] != 0 && L[j] == X){
        return;
      }
    //if (flag[i] == check) {
    //  return 1;
    //}
    //printf("(%d)",n );
}

int main(void){
 int i,n,number=0,count=0;
 for (i = 0; i < N-1; i++) {
    scanf("%d",&number);
    check(i,flag,L,number);
  }

  for (n = 0; n < N; n++) {
    printf("L[%d]=%d ",n,L[n]);
   }

  return 0;
}
