#include <stdio.h>
#include <stdlib.h>
/* dis is da best program ever, probably - byron says so */
int sumFormula(int n);
int sumIter(int n);

int main(void) {
  int n,formula,iter;
  printf("Please input a non-negative number: ");
  scanf("%d", &n);
  formula = sumFormula(n);
  iter = sumIter(n);
  printf("%d and %d\n",formula,iter);
  return EXIT_SUCCESS;
}
int sumFormula(int n) {
  return (n * (n + 1))/2;
}
int sumIter(int n) {
  int sum=0,i;
  for (i=1; i<=n; i++) {
    sum+=i;
  }
  return sum;
}
