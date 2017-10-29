#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b);

int main(void) {
  srand(time(NULL));
  double *n = (double*)malloc(100 * sizeof(double));
  int i;
  for (i=0; i<=99; i++) {
    n[i] = rand() % 500;
  }

  qsort(n, 100, sizeof(double), compare);

  for (i=0; i<=99; i++) {
    printf("%.0lf\n", n[i]);
  }

  free(n);
  return EXIT_SUCCESS;
}

int compare(const void *a, const void *b) {
  return (*(double*)a>*(double*)b);
}
