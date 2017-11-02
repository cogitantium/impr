#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCODELENGTH 25

void translateCode (char *code, char *warehouse, char *product, char *qualifier);
void printCode(char *code, char *warehouse, char *product, char *qualifier);

int main(void) {
  /* initialize desired arrays with constant MAXCODELENGTH for length */
  char  question[1],
        scanString[MAXCODELENGTH],
        code[MAXCODELENGTH],
        warehouse[MAXCODELENGTH],
        product[MAXCODELENGTH],
        qualifier[MAXCODELENGTH];
  int scanCustom;

  /* ask user for custom code */
  do {
    printf("Do you want to scan a product code? If no, we'll use an example (y/n) ");
    scanf(" %c", question);
    scanCustom = (*question == 'y');
  } while(strlen(question) == 0);

  /* scan for custom code if desired by user */
  if (scanCustom) {
    do {
      printf("Input custom barcode (max length is: %d): ", MAXCODELENGTH);
      scanf("%s", scanString);
    } while(!strlen(scanString));
    strcpy(code, scanString);
  } else {
    /* use example code if no custom code is desired*/
    strcpy(code, "ATL1203S14");
  }

  /* invoke functions for translating and printing code nicely */
  translateCode(code, warehouse, product, qualifier);
  printCode(code, warehouse, product, qualifier);

  return EXIT_SUCCESS;
}

void translateCode (char *code, char *warehouse, char *product, char *qualifier) {
  int i, n=0;
  /* search for warehouse location in string */
  while(isalpha(code[i])) {
    i++;
  }
  strncpy(warehouse, code, i);
  warehouse[i] = '\0';

  /* search for product location in string */
  int start = i;
  while(isdigit(code[i])) {
    i++; n++;
  }
  strncpy(product, &code[start], n);
  product[n] = '\0';

  /* calculating qualifier location in string */
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
