#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int year=0;
  double pop=0;
  printf("Please input inhabitants as a non-negative integer: ");
  scanf("%lf",&pop);

  while (pop <= 30000) {
    pop = pop*1.1;
    printf("%.2f\n",pop);
    year++;
  }
  printf("pop: %.2f, years passed: %d\n", pop, year);
  return EXIT_SUCCESS;
}
