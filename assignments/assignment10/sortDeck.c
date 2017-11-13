#include <stdio.h>
#include <stdlib.h>
#define DECKSIZE 54
/* zero-indexed */
#define SUITSIZE 3
#define VALUESIZE 12

struct card {
  /* allowing space for null-character */
  int value;
  int suit;
};
struct card deck[DECKSIZE];

/* clubs -> diamonds -> hearts -> spades */
/* 0=2->8=10, 9=J, 10=Q, 11=K, 12=A */

/* use qsort with rand()-cmpfunc for shuffling */

int initializeDeck(void);

int main(void) {
  initializeDeck();


  return EXIT_SUCCESS;
}

int initializeDeck(void) {
  int i=0, s, v, n;
  /* for each suit {0..3}  */
  for (s=0; s<=SUITSIZE; s++) {
    for (v=0; v<=VALUESIZE; v++) {
      deck[s*VALUESIZE+v].suit = s;
      deck[s*VALUESIZE+v].value = v;
      printf("Card number: %2d \thas .value=%2d \t\tand .suit=%d\n", i, deck[s*VALUESIZE+v].value, deck[s*VALUESIZE+v].suit);
      i++;
    }
  }
  printf("I:%d\n", i);

  for (n=i; n<=DECKSIZE; n++) {
    deck[n].suit = 4;
    printf("Card number: %d\t\thas .suit:%d\n", n, deck[n].suit);
  }
  printf("I:%d\n", i);


  return EXIT_SUCCESS;
}
