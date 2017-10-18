/* this program calculates the greatest common dividor between two integers */
/* necessary libraries are imported for printf(), scanf() and return-definitions */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  /* we initialize our two variables*/
  int a=0,b=0,gcd;
  /* we use a while-function to allow the user more tries, when inputting variables */
  while (a <= 0 || b <= 0) {
    /* we ask the user to input two non-negative variables and read them into a and b */
    printf("Please input two non-negative integers: ");
    scanf(" %d %d", &a, &b);
  }
  /* using a conditional statement we make sure that our variable gcd is set to the lowest read integer */
  gcd =(a>b)?b:a;
  /* we create a while-loop that decreases gcd by one,
  each time the remainder of a and b modulo gcd is not 0 */
  while (a % gcd != 0 || b % gcd != 0) {
    gcd--;
  }
  /* we print the result nicely and include the variables used */
  printf("GCD: %d between input %d and %d.\n", gcd, a, b);
  return EXIT_SUCCESS;
}
