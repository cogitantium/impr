#include <stdio.h>

int main(void) {

  int c1, c2, c3, c4,   scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

  printf("c1 = %c, c2 = %c, c3 = %c, c4 = %c\n", c1, c2, c3, c4);
  printf("scanRes = %d\n", scanRes);

  return 0;
}
