#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 25

int isPalindromeIter(char *str);
int isPalindromeRec(char *str, int n);
int isPalindromeRecInit(char *str);

int main(void) {
  char str[MAXSTRLEN];

  printf("Please input a word for palindrome checking: ");
  gets(str);

  printf("Iterative function returns that string: %s is%s a palindrome\n", str, isPalindromeIter(str)?"":" not");

  printf("Recursive function returns that string: %s is%s a palindrome\n", str, isPalindromeRecInit(str)?"":" not");

  return EXIT_SUCCESS;
}

int isPalindromeIter(char *str) {
  /* initializing strlen without \0 character */
  int i, lenStr = strlen(str) - 1;
  for (i=0; i<=lenStr; i++) {
    if (!(str[i] == str[lenStr-i]))
      return 0;
  }
  return 1;
}

int isPalindromeRecInit(char *str) {
  int n = 0;
  printf("Recursive: %d\n", isPalindromeRec(str, n));
  return isPalindromeRec(str, n);
}

int isPalindromeRec(char *str, int n) {
  int lenStr = strlen(str) - 1;

  if (n <= lenStr - n) {
    if (str[n] == str[lenStr-n]) {
      return isPalindromeRec(str, n+1);
    } else return 0;
  }
  return 1;
}
