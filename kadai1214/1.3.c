#include <stdio.h>
#include <string.h>

#define MAX_TEXT 1024

void PreSuffTable(int PreSuffArray[], char S2[], int S2_len) {
  int j=0,i=1;

for (int count = 0; S2[count]!='\0'; count++) {
    PreSuffArray[count]=0;
  }

  while (i < S2_len) {
    if (S2[j] == S2[i]) {
      PreSuffArray[i] = j+1;
      i++;
      j++;
    }
      else if (j == 0) {
        PreSuffArray[i] = 0;
        i++;
      }
        else if (j != 0) {
          j = PreSuffArray[j-1];
        }
  }
}

int char_search(char S1[], int S1_len, char S2[], int S2_len){
  int S1_pos = 0;
  int S2_pos = 0;
  int PreSuffArray[S2_len];

  PreSuffTable(PreSuffArray, S2, S2_len);

  while (S1_pos < S1_len) {
    if (S1[S1_pos] == S2[S2_pos]) {
      if (S2_pos == S2_len - 1) {
        return S1_pos - S2_pos;
      }
      S1_pos++;
      S2_pos++;
  }else{
           if(PreSuffArray[S2_pos] == PreSuffArray[0]) {
            S1_pos++;
            S2_pos=0;
          }else{
            S2_pos = PreSuffArray[S2_pos];
          }
        }
  }
  return -1;
}

int main() {
  char S1[MAX_TEXT];
  char S2[MAX_TEXT];

  int result;

  printf("Please S1 : ");
  scanf("%s",&S1);
  printf("Please S2 : ");
  scanf("%s",&S2);

  result = char_search(S1,strlen(S1),S2,strlen(S2));

  if (result == -1) {
    printf("Not Strings!!!\n");
  }else{
    printf("Succses!!!\n");
  }
  return 0;
}
