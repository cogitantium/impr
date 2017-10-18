#include <stdio.h>

int main(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%d %d %d", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}
