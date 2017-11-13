#include <stdio.h>
#include <stdlib.h>
#define JOKERS 3
#define DECKSIZE 52
#define SUITSIZE 4
#define VALUESIZE 13

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
  printf("Printing initialized deck nicely\n");
  printDeck();

  return EXIT_SUCCESS;
}

int initializeDeck(void) {
  int s, v, n;
  /* for each suit {0..3} assigning {0.12} to all cards in suit */
  for (s=0; s<SUITSIZE; s++) {
    for (v=0; v<VALUESIZE; v++) {
      deck[s*VALUESIZE+v].suit = s;
      deck[s*VALUESIZE+v].value = v;
    }
  }
  /* assigning deck.suit to "4" for last three cards to represent jokers */
  for (n=DECKSIZE; n<DECKSIZE+JOKERS; n++) {
    deck[n].suit = 4;
  }
  return EXIT_SUCCESS;
}

int printDeck(void) {
  int i;
  for (i=0; i<DECKSIZE+JOKERS; i++) {

    if (deck[i].suit == 4)
      printf("J");
    else {

      if(deck[i].value<=8 && deck[i].suit<4)
        printf("%d", deck[i].value+2);
      else if (deck[i].value == 9)
        printf("J");
      else if (deck[i].value == 10)
        printf("Q");
      else if (deck[i].value == 11)
        printf("K");
      else if (deck[i].value == 12)
        printf("A");

      switch (deck[i].suit) {
        case 0: printf("c"); break;
        case 1: printf("d"); break;
        case 2: printf("h"); break;
        case 3: printf("s"); break;
      }
    }
    /* printing deck sequentially, linebreaking each 13th card */
    printf(" ");
    if ((i+1)%13 == 0 && i>0)
      printf("\n");
  }
  printf("\n");
  return EXIT_SUCCESS;
}
