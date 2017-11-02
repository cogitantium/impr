#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCODELENGTH 25

void translateCode (char *code, char *warehouse, char *product, char *qualifier);
void printCode(char *code, char *warehouse, char *product, char *qualifier);

int main(void) {
  char  question, scanString,
        code[MAXCODELENGTH],
        warehouse[MAXCODELENGTH],
        product[MAXCODELENGTH],
        qualifier[MAXCODELENGTH];
  int scanCustom;

  do {
    printf("Do you want to scan a product code? If no, we'll use an example (y/n) ");
    scanf(" %c", &question);
    scanCustom = (question == 'y');
  } while (strlen(&question) == 0);

  if (scanCustom) {

    do {
      printf("Scanning custom barcode: ");
      scanf("%s", &scanString);
    } while(!strlen(&scanString));
    strcpy(code, &scanString);

  } else {
    strcpy(code, "ATL1203S14");
  }

  translateCode(code, warehouse, product, qualifier);
  printCode(code, warehouse, product, qualifier);

  return EXIT_SUCCESS;
}

void translateCode (char *code, char *warehouse, char *product, char *qualifier) {
  int i, n=0;
  while(isalpha(code[i])) {
    i++;
  }
  strncpy(warehouse, code, i);
  warehouse[i] = '\0';

  int start = i;
  while(isdigit(code[i])) {
    i++; n++;
  }
  strncpy(product, &code[start], n);
  product[n] = '\0';


  int lengthQualifier = strlen(code) - i;
  strncpy(qualifier, &code[i], lengthQualifier);
  qualifier[lengthQualifier] = '\0';

}

void printCode(char *code, char *warehouse, char *product, char *qualifier) {
  printf("For scanned code:\t%s\n", code);
  printf("Warehouse location:\t%s\n", warehouse);
  printf("Product identifier:\t%s\n", product);
  printf("Qualifier identifier:\t%s\n", qualifier);
}
