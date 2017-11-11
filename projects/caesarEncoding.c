#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTRLEN 25

/* TODO: int-value of characters can be used for char-arithmetic, consider using tolower() */

int main(void) {
  char str[MAXSTRLEN], res[MAXSTRLEN];

  printf("Input string for Caesar-encoding: ");
  scanf(" %s", str);


  return EXIT_SUCCESS;
}

void encode(char *str, char *res) {
  int i, n;


}

int ceasar(char c) {
  return tolower(c) - 'a';
}
