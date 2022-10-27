#include <stdio.h>

int main(int argc, char const *argv[]) {
  int j=0,i=1;
  char String[10] = "dododd";
  PrefixSuffixArray = [0];

  while () {
    if (String[j] == String[i]) {

      i++;
      j++;
    }
      else if (j == 0) {
        i++;
      }
        else if (j != 0) {
          j = PrefixSuffixArray[j-1];
        }
  }
  printf("%s\n", String);
  return 0;
}
