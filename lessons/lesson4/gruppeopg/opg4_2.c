#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int m,n,k=0,i=0,count=0;
  while (k<1) {
    printf("Please input non-negative numbers for m, n and k: ");
    scanf(" %d %d %d",&m,&n,&k);
  }
  for (i = m;i <= n;i++) {
    if (i%k==0) {
      count = count + i;
      printf("Adding to count: %d\n",count);
    }
  }
printf("Final count of integers divisible by %d, between %d and %d: %d\n",k,m,n,count);

  return EXIT_SUCCESS;
}
