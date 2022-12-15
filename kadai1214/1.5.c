#include <stdio.h>
#include <string.h>

#define MAX_TEXT 1024

int char_search(char S1[], int S1_len, char S2[], int S2_len){
  int S1_pos = 0;
  int S2_pos = 0;
  int S1_GAP[S1_len+1];
  int S2_GAP[S2_len+1];
  int M[S1_len][S2_len];
  int LS[S1_len][S2_len];
  int DS[S1_len][S2_len];
  int US[S1_len][S2_len];

  int count_x=1,count_y;

  memset(S1_GAP, 0, sizeof S1_GAP);
  memset(S2_GAP, 0, sizeof S2_GAP);

  for (count_y = 0; count_y < S2_len+1; count_y++) {
    if (count_y == 0) {
      printf("      |");
      for(S1_pos=0; S1_pos<S1_len; S1_pos++){
        printf("%-8c|", S1[S1_pos]);
      }
      printf("\n");

      printf("%6d|",S1_GAP[0]=0);

      if (count_x == 1 && count_y == 0) {
        for(count_x=1; count_x<S1_len+1; count_x++){
          S1_GAP[count_x] = S1_GAP[count_x-1] - 2;
          printf("%-8d|", S1_GAP[count_x]);
        }
      }

      printf("\n");

      for(int b=0; b<(S1_len * 9)+7; b++){
        printf("-");
      }
    }
    else{
        S2_GAP[count_y] = S2_GAP[count_y-1] - 2;
        printf("%2c%4d|",S2[count_y-1],S2_GAP[count_y]);
      }
    printf("\n");

  }

}

int main() {
  char S1[MAX_TEXT];
  char S2[MAX_TEXT];

  int result;

  printf("Please S1 : ");
  scanf("%s",&S1);
  printf("Please S2 : ");
  scanf("%s",&S2);

  char_search(S1,strlen(S1),S2,strlen(S2));

  return 0;
}
