#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCODELENGTH 25

int main(void) {
  char *scanString, question,
        code[MAXCODELENGTH],
        warehouse[MAXCODELENGTH],
        product[MAXCODELENGTH],
        qualifier[MAXCODELENGTH];
  int strLength, scanCustom,
      codeLength = (MAXCODELENGTH);

  do {
    printf("Do you want to scan a product code? (y/n) if not we'll use an example ");
    scanf(" %c", &question);
    scanCustom = (question == 'y');
  } while (strlen(&question) == 0);

  if (scanCustom) {
    do {
      printf("Scanning custom barcode: ");
      scanf("%s", scanString);
      strLength = strlen(scanString);
    } while(!(strLength==codeLength));
  } else {
    code = "ATL1203S14";
  }

  return EXIT_SUCCESS;
}
