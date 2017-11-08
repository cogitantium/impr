#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* calculate runtime in integers for increment */
int main(void) {
  int i, n, p;
  long int initEpoch, endEpoch;

  printf("Input desired iterations: ");
  scanf(" %d", &n);

  initEpoch = time(NULL);
  for(i=0; i<=n; i++) {
    p++;
  }

  endEpoch = time(NULL);
  printf("\nElapsed time: %ld\n", (endEpoch - initEpoch));

  return EXIT_SUCCESS;
}
