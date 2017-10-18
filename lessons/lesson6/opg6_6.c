#include <stdio.h>
#include <stdlib.h>

#define USDTOEUR 0.89
#define USDTODKK 6.66
#define USDTORUB 66.43
#define USDTOYEN 119.9

void convCurrency(double inputDollars, double *convEuro, double *convDkk, double *convRubles, double *convYen);

int main(void) {
  double inputDollars, convEuro, convDkk, convRubles, convYen;

  printf("Please input amount of dollars to be converted: ");
  scanf(" %lf", &inputDollars);

  convCurrency(inputDollars, &convEuro, &convDkk, &convRubles, &convYen);

  printf("$%.2f is %.2f EUR, %.2f DKK, %.2f Rubles and %.2f Yen.\n", inputDollars, convEuro, convDkk, convRubles, convYen);
  return EXIT_SUCCESS;
}

void convCurrency(double inputDollars, double *convEuro, double *convDkk, double *convRubles, double *convYen) {
  *convEuro = USDTOEUR * inputDollars;
  *convDkk = USDTODKK * inputDollars;
  *convRubles = USDTORUB * inputDollars;
  *convYen = USDTOYEN * inputDollars;
  }
