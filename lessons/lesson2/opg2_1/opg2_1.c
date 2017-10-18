#include <stdio.h>

int main(void) {

  int sum1 =    10  +   11  +  12,
      sum2  =  010 +   011 +  012,
      sum3  = 0x10 +  0x11 + 0x12;

  printf("sum1 =  %d\n", sum1);
  printf("sum2 =  %d\n", sum2);
  printf("sum3 =  %d\n", sum3);

  return 0;
}
