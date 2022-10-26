#include <stdio.h>

#define NUM 4

void sort(int *f);

int main() {

  int x[NUM], y[NUM];
  double sum;

  printf("Input format: [LP1 LP2 RP1 RP2]\n");
  scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
  printf("Input format: [LQ1 LQ2 RQ1 RQ2]\n");
  scanf("%d %d %d %d", &x[2], &y[2], &x[3], &y[3]);

  sort(x);
  sort(y);

  sum = (double)(x[2] - x[1]) * (y[2] - y[1]);

  printf("Answer is %lf\n", sum);

  return 0;
}

void sort(int *f) {
  int i, j, tmp;
  for (i=0; i < NUM-1; i++) {
    for (j = i+1; j < NUM; j++) {
      if (f[i]<f[j]) {
        tmp = f[i];
        f[i] = f[j];
        f[j] = tmp;
      }
    }
  }
}
