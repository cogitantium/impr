#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap(double a, double b, int n, double (*f)(double));
double g(double x);
double h(double x);

int main(void) {
  int n;
  printf("Calculating the area of g(x)=x^2*sin(x) in the interval [0,3.14159]\n");
  for (n=2; n<=128; n*=2) {
    printf("When using n = %3d, the area of g(x) is: %lf\n", n, trap(0, 3.14159, n, g));
  }

  printf("\nCalculating the area of f(x)=sqrt(4-x^2) in the interval [-2,2]\n");
  for (n=2; n<=128; n*=2) {
    printf("When using n = %3d, the area of h(x) is: %lf\n", n, trap(-2, 2, n, h));
  }
  return EXIT_SUCCESS;
}

double trap(double a, double b, int n, double (*f)(double)) {
  int i;
  double area = f(a)+f(b), h = (b-a)/n;

  for (i=1; i<n; i++) {
    double xi = a+i*h;
    area += 2*f(xi);
  }
  return area *= h/2;
}

double g(double x) {
  return x*x*sin(x);
}

double h(double x) {
  return sqrt(4-x*x);
}
