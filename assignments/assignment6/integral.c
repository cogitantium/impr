#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap(double a, double b, int n, double (*f)(double));
double g(double x);
double h(double x);

int main(void) {
  int n;
  /* we call our trap-function with increasing resolution as multiples of 2 up to 128
  for both functions, parsing the interval, resolution and the function as parameters */
  printf("Calculating the area of g(x)=x^2*sin(x) in the interval [0,3.14159]\n");
  for (n=2; n<=128; n*=2) {
    printf("When using n = %3d, the area of g(x) is: %.4lf\n", n, trap(0, 3.14159, n, g));
  }

  printf("\nCalculating the area of h(x)=sqrt(4-x^2) in the interval [-2,2]\n");
  for (n=2; n<=128; n*=2) {
    printf("When using n = %3d, the area of h(x) is: %.4lf\n", n, trap(-2, 2, n, h));
  }
  return EXIT_SUCCESS;
}

double trap(double a, double b, int n, double (*f)(double)) {
  int i;
  /* we add f(a) and f(b) to the total and calculate h */
  double area = f(a)+f(b), h = (b-a)/n;

  /* for each step we add 2*f(xi) to the total */
  for (i=1; i<n; i++) {
    /* xi are the steps between a and b */
    double xi = a+i*h;
    area += 2*f(xi);
  }
  /* we multiply with h/2 to find the area of each trapezoid */
  return area *= h/2;
}

double g(double x) {
  return x*x*sin(x);
}

double h(double x) {
  return sqrt(4-x*x);
}
