/* graded 3/3 with comments on good use of qsort, nice coding style and function abstracting */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* defining each characteristic of deck individually for flexibility */
#define JOKERS 3
#define SUITSIZE 4
#define VALUESIZE 13
#define DECKSIZE (SUITSIZE * VALUESIZE + JOKERS)

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

struct card { int value; int suit; };

int initializeDeck(struct card deck[]);
void printDeck(struct card deck[], char *printType);
char * printDeckValue(struct card deck[], int i);
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
      printf(COLOR_YELLOW "J" COLOR_RESET);
    else {
      /* using switch for printing and ANSI-colouring for card suit */
      switch (deck[i].suit) {
        case 0: printf(COLOR_CYAN "%sc" COLOR_RESET, printDeckValue(deck, i)); break;
        case 1: printf(COLOR_RED "%sd" COLOR_RESET, printDeckValue(deck, i)); break;
        case 2: printf(COLOR_RED "%sh" COLOR_RESET, printDeckValue(deck, i)); break;
        case 3: printf(COLOR_CYAN "%sc" COLOR_RESET, printDeckValue(deck, i)); break;
      }
    }
    /* printing deck sequentially, linebreaking each 13th card */
    printf(" ");
    if ((i+1)%VALUESIZE == 0 && i>0)
      printf("\n");
  }
  printf("\n\n");
}

char * printDeckValue(struct card deck[], int i) {
  switch (deck[i].value) {
    case 0: return "2";
    case 1: return "3";
    case 2: return "4";
    case 3: return "5";
    case 4: return "6";
    case 5: return "7";
    case 6: return "8";
    case 7: return "9";
    case 8: return "10";
    case 9: return "J";
    case 10: return "Q";
    case 11: return "K";
    case 12: return "A";
    default: return "Invalid value!";
  }
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
