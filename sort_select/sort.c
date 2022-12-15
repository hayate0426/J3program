#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

void Bubble_Sort(int array[], int num);
void DisplaySorts(int array[], int num);
void swap(int *a, int *b);

int main() {
  char KeyBoardInput,Options;
  int num;
  printf("Len = ");
  scanf("%d",&num);
  int array[num];

    for (int count = 0; count <num; count++) {
      scanf("%d", &array[count]);
    }

  while(1)
  {
  printf("S: Selection Sort, B: Bubble Sort, Q: Quick Sort, D: Display\n");
  printf("Type desired options(S,B,Q,D):");
  scanf("%s",&KeyBoardInput);
  Options=toupper(KeyBoardInput);
  switch (Options)
   {
    case 'S':
  //  Selection_Sort();
    break;

    case 'B':
    Bubble_Sort(array, num);
    break;

    case 'Q':
    //Quick_Sort();
    break;

    case 'D':
    DisplaySorts(array, num);
    return 0;

    default:
    printf("Invalid Option.\n");
    break;
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

void Bubble_Sort(int array[], int num)
{
  int i, j;

  for (i=num-1; i>0; i--) {
    for (j=0; j<i; j++) {
      if(array[j]<array[j+1]) {
        swap(&array[j], &array[j+1]);
      }
    }
  }
}

void DisplaySorts(int array[], int num)
{
  int i, j;
  for (i = 0; i < num; i++) {
    printf("%d\n",array[i] );
  }
}
