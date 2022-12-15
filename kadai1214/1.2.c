#include <stdio.h>
#include <string.h>

int main() {
  int j=0,i=1;
  int StringLength;
  char String[10];

  printf("Please String : ");
  scanf("%s", &String);

  StringLength = strlen(String);
  int PrefixSuffixArray[StringLength];

for (int count = 0; String[count]!='\0'; count++) {
    PrefixSuffixArray[count]=0;
  }

  while (i < StringLength) {
    if (String[j] == String[i]) {
      PrefixSuffixArray[i] = j+1;
      i++;
      j++;
    }
      else if (j == 0) {
        PrefixSuffixArray[i] = 0;
        i++;
      }
        else if (j != 0) {
          j = PrefixSuffixArray[j-1];
        }
  }
  printf("P[] = ");
  for (int count = 0; count < StringLength; count++) {
    printf("%d,", PrefixSuffixArray[count]);
  }
  return 0;
}
