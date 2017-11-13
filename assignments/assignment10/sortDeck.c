#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define JOKERS 3
#define DECKSIZE 52
#define SUITSIZE 4
#define VALUESIZE 13

struct card {
  int value;
  int suit;
};
struct card deck[DECKSIZE+JOKERS];

/* clubs -> diamonds -> hearts -> spades */
/* 0=2->8=10, 9=J, 10=Q, 11=K, 12=A */

int initializeDeck(void);
void printDeck(void);
void shuffleDeck();
int sortDeck();
int compareCards();

int main(void) {
  initializeDeck();
  printf("Printing initialized deck nicely\n");
  printDeck();
  shuffleDeck();
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

void printDeck(void) {
  int i;
  for (i=0; i<DECKSIZE+JOKERS; i++) {

    if (deck[i].suit == 4)
      printf("J ");
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
    if ((i+1)%VALUESIZE == 0 && i>0)
      printf("\n");
  }
  printf("\n");
}

void shuffleDeck () {
  /*  To shuffle an array a of n elements (indices 0..n-1):
  for i from 0 to n−2 do
  n ← random integer such that i ≤ n < n
  exchange a[i] and a[n]

  rand() % (max_number + 1 - minimum_number) + minimum_number */
  srand(time(NULL));
  struct card temp;
  int i, n;

  for (i=0; i<=DECKSIZE+JOKERS-2; i++) {
    n = rand() % ((DECKSIZE+JOKERS-2) + 1 - i) + i;
    temp = deck[n];
    deck[n] = deck[i];
    deck[i] = temp;
  }
  printDeck();
}
