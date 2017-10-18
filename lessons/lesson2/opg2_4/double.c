#include <stdio.h>

int main(void) {

  double d, e, f;

  printf("Enter three real numbers: ");
  scanf("%lf %lf %lf", &d, &e, &f);
 /* der forventes formatet double, men var float */ 
  printf("The average is: %.2f\n", (d + e + f) / 3.0);
    
  return 0;
}
