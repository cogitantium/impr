#include <stdio.h>
#include <stdlib.h>

/* defining known constants */
#define HUNDRED 100
#define FIFTY 50
#define TWENTY 20
#define TEN 10

/* prototyping functions for calculations */
void calculateBillAmount(int requestWithdraw, int *billsHundred, int *billsFifty, int *billsTwenty, int *billsTen);
int calculateSingleAmount(int *remainder, int sizeBill);
void separator(int *withdrawnBills);

int main(void) {
  int requestWithdraw, withdrawnBills, billsHundred, billsFifty, billsTwenty, billsTen;

  /* keeps scanning for input, until user requests a non-legative withdrawal amount divisible by 10 */
  do {
    printf("Input non-negative amount divisible with 10, please: ");
    scanf(" %d",&requestWithdraw);
  } while(requestWithdraw<0 || !requestWithdraw%10);

  /* calls function for calculating the amount of individual bills for each category */
  calculateBillAmount(requestWithdraw, &billsHundred, &billsFifty, &billsTwenty, &billsTen);

  /* calculates number of categories that exist, using NOT false evaluation */
  withdrawnBills = !!billsHundred + !!billsFifty + !!billsTwenty + !!billsTen;

  printf("You've requested a withdrawal of $%d, we'll give you: ",requestWithdraw);
  if (billsHundred) {
    printf("%d hundred dollar %s",billsHundred,billsHundred>1?"bills":"bill");
    separator(&withdrawnBills);
  } if (billsFifty) {
    printf("%d fifty dollar %s",billsFifty,billsFifty>1?"bills":"bill");
    separator(&withdrawnBills);
  } if (billsTwenty) {
    printf("%d twenty dollar %s",billsTwenty,billsTwenty>1?"bills":"bill");
    separator(&withdrawnBills);
  } if (billsTen) {
    printf("%d ten dollar %s",billsTen,billsTen>1?"bills":"bill");
    separator(&withdrawnBills);
  }
  return EXIT_SUCCESS;
}

void calculateBillAmount(int requestWithdraw, int *billsHundred, int *billsFifty, int *billsTwenty, int *billsTen) {
  int remainder = requestWithdraw;
  *billsHundred = calculateSingleAmount(&remainder,HUNDRED);
  *billsFifty = calculateSingleAmount(&remainder,FIFTY);
  *billsTwenty = calculateSingleAmount(&remainder,TWENTY);
  *billsTen = calculateSingleAmount(&remainder,TEN);
}

int calculateSingleAmount(int *remainder, int sizeBill) {
  int tempRemainder = *remainder/sizeBill;
  *remainder = *remainder%sizeBill;
  return tempRemainder;
}

void separator(int *withdrawnBills) {
  (*withdrawnBills)--;
  if (*withdrawnBills>=2) {
    printf(", ");
  } else if (*withdrawnBills==1) {
    printf(" and ");
  } else {
    printf(".\n");
  }
}
