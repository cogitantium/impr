/* graded 3/3 by Michael Christensen with no comments */
/* we import libraries needed */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* we prototype our distinct functions */
void solveQuadratic(double a, double b, double c, double d);
double solveDiscriminant(double a, double b, double c);
double solveRootOne(double a, double b);
double solveRootTwoPos(double a, double b, double c);
double solveRootTwoNeg(double a, double b, double c);

int main(void) {
  double a, b, c, discriminant;
  /* we use a boolean variable to continue until we reach a non-computable input */
  int halt = 0;

  do {
    printf("Please input coefficients a, b and c in ax^2+bx+c: ");
    scanf(" %lf %lf %lf", &a, &b, &c);
    /* we protect against the first coefficient, a, being assigned to 0, as we can't divide by zero */
    if (a != 0) {
      discriminant = solveDiscriminant(a, b, c);
      solveQuadratic(a, b, c, discriminant);
    } else {
      halt = 1;
    }
  } while (!halt);
  return EXIT_SUCCESS;
}

void solveQuadratic(double a, double b, double c, double discriminant) {
  /* if the discriminant is less than zero, we've got no roots */
  if (discriminant < 0) {
    printf("No roots found\n");
    /* if the discriminant is exactly 0, we've got a single root and call solveRootOne() */
  } else if (discriminant == 0) {
    printf("One root found: %.2f\n", solveRootOne(a, b));
    /* if the discriminant is larger than zero, we've got multiple roots and call solveRootTwo*() */
  } else {
    printf("Two roots found: %.2f and %.2f\n", solveRootTwoPos(a, b, c), solveRootTwoNeg(a, b, c));
  }
}
/* we implement separate functions for each of the calculations */
double solveDiscriminant(double a, double b, double c) {
  return b * b - 4 * a * c;
}

double solveRootOne(double a, double b) {
  return -b/(2*a);
}

double solveRootTwoPos(double a, double b, double c) {
  return (-b + sqrt(solveDiscriminant(a,b,c)))/(2*a);
}

double solveRootTwoNeg(double a, double b, double c) {
  return (-b - sqrt(solveDiscriminant(a,b,c)))/(2*a);
}
