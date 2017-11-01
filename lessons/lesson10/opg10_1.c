#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
 strRev(char *str);
void printChars(char *str);

int main(void) {

  char strShaq[] = "MansNotHot";
  char strKurt[] = "KurtKlikGod";

  printf("First string: %s\n", strShaq);
  printf("Second string: %s\n", strKurt);

  printChars(strShaq);
  strRev(strShaq);
  printf("\n");
  printChars(strShaq);

  return EXIT_SUCCESS;
}

void strRev(char *str) {
  int a, b=strlen(str)-1, strLength=strlen(str);

  char revStr[strLength];

  for (a=0; a<strLength; a++, b--) {
    revStr[b] = str[a];
  }

  revStr[strLength] = '\0';

  strcpy(str, revStr);
}

void printChars(char *str) {
  int i, strLength = strlen(str);
  for (i=0; i<=strLength-1; i++) {
    printf("str[%d] char: %c\n", i, str[i]);
  }
}
