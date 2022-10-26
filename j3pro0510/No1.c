#include<stdio.h>

#define NUM 50

int main(void){
int n = 0,flag[1];
int a[10+1];

for (n = 0; n < 10; n++) {
  flag[n]=1;
}

for (n = 0; n < 10; n++) {
  if (n == 0){
    a[n] = 0;
     }
   else if (a[n-1] - n>0 && flag[a[n-1]-n] == 0) {
     a[n] = a[n-1]-n;
    }
    else{
      a[n] = a[n-1]+n;
      flag[a[n]] = 1;
   }
  printf("%d\n",a[n] );
}

  return 0;
}
