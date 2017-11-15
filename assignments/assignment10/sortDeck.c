#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* defining each characteristic of deck individually for flexibility */
#define JOKERS 3
#define SUITSIZE 4
#define VALUESIZE 13
#define DECKSIZE (SUITSIZE * VALUESIZE + JOKERS)

struct card { int value; int suit; };

int initializeDeck(struct card deck[]);
void printDeck(struct card deck[], char *printType);
void shuffleDeck(struct card deck[]);
void sortDeck(struct card deck[]);
int compareFunc(const void * card1, const void * card2);

int main(void) {
  struct card deck[DECKSIZE];
  srand(time(NULL));

  initializeDeck(deck);
  printDeck(deck, "initialized");

  shuffleDeck(deck);
  printDeck(deck, "shuffled");

  sortDeck(deck);
  printDeck(deck, "sorted");
  return EXIT_SUCCESS;
}

int initializeDeck(struct card deck[]) {
  int n, v;
  /* for each suit {0..3} assigning {0.12} to all cards in given suit */
  for (n=0; n<SUITSIZE; n++) {
    for (v=0; v<VALUESIZE; v++) {
      deck[n*VALUESIZE+v].suit = n;
      deck[n*VALUESIZE+v].value = v;
    }
  }
  /* assigning 4 to deck.suit for last cards to represent jokers */
  for (n=SUITSIZE * VALUESIZE; n<DECKSIZE; n++) {
    deck[n].suit = 4;
  }
  return EXIT_SUCCESS;
}

/* printing with format of uppercase value, herein also jokers, and lowercase suit */
void printDeck(struct card deck[], char *printType) {
  int i;
  /* handling grammar for different decks being printed */
  printf("Printing %s deck nicely\n", printType);
  for (i=0; i<DECKSIZE; i++) {
    /* handling jokers first */
    if (deck[i].suit == 4)
      printf("J");
    else {
      /* using switch for face cards and suits and arithmetic for numerals */
      switch (deck[i].value) {
        case 9: printf("J"); break;
        case 10: printf("Q"); break;
        case 11: printf("K"); break;
        case 12: printf("A"); break;
        default: printf("%d", deck[i].value + 2);
      }
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
  printf("\n\n");
}

void shuffleDeck(struct card deck[]) {
  struct card temp;
  int i, n;
  /* implementing Fisher-Yates algorithm for shuffling deck */
  for (i=0; i < DECKSIZE - 1; i++) {
    n = rand() % (DECKSIZE - i) + i;
    temp = deck[n];
    deck[n] = deck[i];
    deck[i] = temp;
  }
}

void sortDeck(struct card deck[]) {
  qsort(deck, DECKSIZE, sizeof(struct card), compareFunc);
}

int compareFunc(const void * card1, const void * card2) {
  struct card * a = (struct card *) card1;
  struct card * b = (struct card *) card2;

  if ( (* a).suit < (* b).suit ) return -1;
  else if ( (* a).suit > (* b).suit ) return 1;
  else if ( (* a).value < (* b).value ) return -1;
  else if ( (* a).value > (* b).value ) return 1;
  else return 0;
}
