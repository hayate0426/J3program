#include <stdio.h>

#define NUM 4

void bubble_sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
 int array[NUM],i;
 for (i = 0; i < NUM+1; i++) {
   array[i]=i;
 }

 bubble_sort(array);

 for (i = 0; i < 3; i++) {
   printf("%d\n",array[i] );
 }

  return 0;
}

void bubble_sort(int array[])
{
  int i, j;

  for (i=NUM; i>0; i--) {
    for (j=0; j<i; j++) {
      if(array[j]<array[j+1]) {
        swap(&array[j], &array[j+1]);
      }
    }
  }

}
void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
