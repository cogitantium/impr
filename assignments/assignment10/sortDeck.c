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
int printDeck(void);

int main(void) {
  initializeDeck();
  printDeck();

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
  for (n=i; n<=DECKSIZE; n++) {
    deck[n].suit = 4;
    printf("Card number: %d\t\thas .suit:%d\n", n, deck[n].suit);
  }
  return EXIT_SUCCESS;
}

/* clubs -> diamonds -> hearts -> spades */
/* 0=2->8=10, 9=J, 10=Q, 11=K, 12=A */

int printDeck(void) {
  int i;
  for (i=0; i<=DECKSIZE; i++) {

    if (deck[i].suit == 4)
      printf("J");
    else {

    if(deck[i].value<=8)
      printf("%d", deck[i].value+2);
    else if (deck[i].value == 9)
      printf("J");
    else if (deck[i].value == 10)
      printf("Q");
    else if (deck[i].value == 11)
      printf("K");
    else if (deck[i].value == 12)
      printf("A");
    else
      printf("Invalid value!");

    switch (deck[i].suit) {
      case 0: printf("c");
      case 1: printf("d");
      case 2: printf("h");
      case 3: printf("s");
    }



    }
    printf(" - ");
  }
  return EXIT_SUCCESS;
}
