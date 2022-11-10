#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = NULL;
  char c;
  int chr;

  fopen_s(&fp, "cityinfo.txt", "r");
  if (fp == NULL) {
    printf("error\n");
    return 0;
  }

  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  fclose(fp);

  return 0;
}
