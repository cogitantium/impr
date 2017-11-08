#include <stdio.h>
#include <stdlib.h>

int quotient(int dividend, int divisor);
int modulus(int dividend, int divisor);

int main(void) {
  int dividend, divisor;
  printf("Input dividend and divisor respectively: ");
  scanf("%d %d", &dividend, &divisor);

  printf("%d\n", quotient(dividend, divisor));
  printf("%d\n", modulus(dividend, divisor));


  return EXIT_SUCCESS;
}

int quotient(int dividend, int divisor) {
  if (dividend >= divisor) {
    dividend -= divisor;
    return 1 + quotient(dividend, divisor);
  }
  return 0;
}

int modulus(int dividend, int divisor) {
  if (dividend >= divisor) {
    return modulus(dividend-divisor, divisor);
  } else {
    return dividend;
  }
}
