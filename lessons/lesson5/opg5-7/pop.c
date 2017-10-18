#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double popStart, rateAnno, popLimit;

  printf("Input population: ");
  scanf("%lf %lf %lf", &popStart, &rateAnno, &popLimit)
}

int popInc(double popStart, double rateAnno, double popLimit) {
  int year
  while (popStart <= popLimit) {
    popStart *= (1+rateAnno);
    year++;
  }
  return year;
}
