#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int n,properResult,testResult=0,i;
  printf("Please only input non-negative integers: ");
  scanf(" %d", &n);
  for (i=1; i<=n; i++) {
    testResult = testResult+i;
    printf("%d: %d. ", i, testResult);
  }
  printf("\ntestResult: %d\n", testResult);
  properResult = (n * (n + 1))/2;
  printf("properResult: %d\n", properResult);
  printf("testResult and properResult equal: %s\n",testResult==properResult?"Yis":"Nop");
return EXIT_SUCCESS;
}
