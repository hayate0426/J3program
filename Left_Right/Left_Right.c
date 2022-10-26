#include <stdio.h>
#include <stdlib.h>

typedef struct num {
  int Data;
  struct num *Left, *Right;
} Number;


Number *FirstNumber = NULL;


int main(void) {
  int i;
  int Sequence[12] = {13, 8, 10, 21, 6, 12, 7, 19, 45, 51, 33, 6};
  Number *NewNumber, *TargetNumber;


  for (i = 0; i < 12; i++) {
    NewNumber = (Number *) malloc(sizeof(Number));
    NewNumber -> Data = Sequence[i];
    NewNumber -> Left = NULL;
    NewNumber -> Right = NULL;
    if (FirstNumber == NULL) {
      FirstNumber = NewNumber;
      printf("[%d] : FirstNumber\n", Sequence[i]);
      continue;
    }
    TargetNumber = FirstNumber;
    while (1) {
      if (TargetNumber -> Data > Sequence[i]) {
	if (TargetNumber -> Left == NULL) {
	  TargetNumber -> Left = NewNumber;
	  printf("[%d]=[%d]left\n", Sequence[i], TargetNumber -> Data);
	  break;
	} else {
	  TargetNumber = TargetNumber -> Left;
	}
      }
      if (TargetNumber -> Data < Sequence[i]) {
	if (TargetNumber -> Right == NULL) {
	  TargetNumber -> Right = NewNumber;
	  printf("[%d]=[%d]right\n", Sequence[i], TargetNumber -> Data);
	  break;
	} else {
	  TargetNumber = TargetNumber -> Right;
	}
      }
      if (TargetNumber -> Data == Sequence[i]) {
	printf("[%d]=already\n", Sequence[i]);
	break;
      }
    }
  }
  return 0;
}
