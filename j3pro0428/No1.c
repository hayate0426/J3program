#include <stdio.h>

int F(int);

int main ()
{
int i,q,X = 0;

 scanf("%d",&X);
 for (i = 0; i < X; i++) {
   q=F(i);
   printf("%d ",q );
  }

 printf("\n");
 return 0;
 }

int F(int i)
{
  if(i == 0) return 0;
   else if(i == 1) return 1;

  return F(i - 2) + F(i - 1);
 }
