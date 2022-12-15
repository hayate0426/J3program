#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 1024

int check_Arr(int M_pos, int LS_pos, int DS_pos, int US_pos){
  int max;
  max = M_pos;

  if (max < LS_pos) {
    max = LS_pos;
  }
  if (max < DS_pos) {
    max = DS_pos;
  }
  if (max < US_pos) {
    max = US_pos;
  }
  return max;
}

int char_search(char S1[], int S1_len, char S2[], int S2_len){
  int S1_pos ;
  int S2_pos ;
  int result;
  int S1_GAP[S1_len+1];
  int S2_GAP[S2_len+1];
  int M[S1_len][S2_len],M_pos=0;
  int LS[S1_len][S2_len],LS_pos=0;
  int DS[S1_len][S2_len],DS_pos=0;
  int US[S1_len][S2_len],US_pos=0;

  memset(S1_GAP, 0, sizeof S1_GAP);
  memset(S2_GAP, 0, sizeof S2_GAP);
  memset(M, 0, sizeof M);
  memset(LS, 0, sizeof LS);
  memset(DS, 0, sizeof DS);
  memset(US, 0, sizeof US);

  S1_GAP[0] = -2;
  S2_GAP[0] = -2;


  for ( S1_pos = 1; S1_pos < S1_len; S1_pos++) {
    S1_GAP[S1_pos] = S1_GAP[S1_pos-1] - 2;
    printf("[%d]",S1_GAP[S1_pos]);
  }
  for (S2_pos = 1; S2_pos < S2_len; S2_pos++) {
    S2_GAP[S2_pos] = S2_GAP[S2_pos-1] - 2;
    printf("%d",S2_GAP[S2_pos]);
  }

  printf("\n");

  for (S2_pos = 0; S2_pos < S2_len; S2_pos++) {
    for (S1_pos = 0; S1_pos < S1_len; S1_pos++) {
      if (S1[S1_pos]==S2[S2_pos]) {
        M[S1_pos][S2_pos] = 2;
      }
        else{
          M[S1_pos][S2_pos] = -1;
        }

        printf("%3d ", M[S1_pos][S2_pos]);

      if (S1_pos == 0) {
        LS[S1_pos][S2_pos] = S2_GAP[S2_pos] + S1_GAP[S1_pos];
      }
      else {
        M_pos = M[S1_pos-1][S2_pos];
        LS_pos = LS[S1_pos-1][S2_pos];
        DS_pos = DS[S1_pos-1][S2_pos];
        US_pos = US[S1_pos-1][S2_pos];
        result = check_Arr(M_pos ,LS_pos ,DS_pos ,US_pos );
        printf("[%3d]", result);
        LS[S1_pos][S2_pos] = result -2;
      }
      if (S1_pos == 0) {
        DS[S1_pos][S2_pos] = M[S1_pos][S2_pos];
      }
      else {
        M_pos = M[S1_pos-1][S2_pos-1];
        LS_pos = LS[S1_pos-1][S2_pos-1];
        DS_pos = DS[S1_pos-1][S2_pos-1];
        US_pos = US[S1_pos-1][S2_pos-1];
        result = check_Arr(M_pos ,LS_pos ,DS_pos ,US_pos );
        printf("[%3d]", result);
        LS[S1_pos][S2_pos] = result + M[S1_pos][S2_pos];
      }
        printf("%3d|", LS[S1_pos][S2_pos]);
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
