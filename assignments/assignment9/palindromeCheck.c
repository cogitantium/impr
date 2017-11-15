/* graded 3/3 by McCollin with comments on good naming, abstracting functions and readability */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 25

int isPalindromeIter(char *str);
int isPalindromeRecInit(char *str);
int isPalindromeRec(char *str, int n);

int main(void) {
  char str[MAXSTRLEN];

  printf("Please input a word for palindrome checking: ");
  /* using deprecated gets() for including whitespace in sentences */
  gets(str);

  /* using conditional statements for printing result */
  printf("Iterative function returns that string: %s, is%s a palindrome\n", str, isPalindromeIter(str)?"":" not");

  printf("Recursive function returns that string: %s, is%s a palindrome\n", str, isPalindromeRecInit(str)?"":" not");
  return EXIT_SUCCESS;
}

int isPalindromeIter(char *str) {
  /* initializing strlen without \0 character */
  int i, lenStr = strlen(str) - 1;
  /* comparing each character at index i to strLen - i */
  for (i=0; i<=lenStr; i++) {
    /* if not equal for for all, return false */
    if (!(str[i] == str[lenStr-i]))
      return 0;
  }
  return 1;
}

int isPalindromeRecInit(char *str) {
  /* using helper-function to initialize n to zero before parsing */
  int n = 0;
  return isPalindromeRec(str, n);
}

int isPalindromeRec(char *str, int n) {
  int lenStr = strlen(str) - 1;

  /* if indexes haven't gone past eachother, continue */
  if (n <= lenStr - n) {
    /* if characters are equal to eachother, recurse once again, else return false */
    if (str[n] == str[lenStr-n]) {
      return isPalindromeRec(str, n+1);
    } else return 0;
  }
  /* if no mismatches have been found, return true */
  return 1;
}
