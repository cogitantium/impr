#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXFORRET 4
#define MAXHOVEDRET 4
#define MAXDESSERT 4

enum forret {guacamole,tarteletter,lakserulle,graeskarsuppe};
enum hovedret {gyldenkaal,hakkeboef,gullash,forloren_hare};
enum dessert {pankager_med_is,gulerodskage,chokolademousse,citronfromage};

void maaltid() {
  int i;
  for (i=0;i<=25;i++) {
    printf("Menu: %d",i);
    printf("Forret: %s",transForret(););
  }
}

enum forret randForret() {
  return (enum forret)(rand()%MAXFORRET);
}

char* transForret(enum forret a) {
  switch(a){
      case guacamole:
          return "guacamole";
          break;
      case tarteletter:
          return "tarteletter";
          break;
      case lakserulle:
          return "lakserulle";
          break;
      case graeskarsuppe:
          return "graeskarsuppe";
          break;
  }
}

enum hovedret randHovedret() {
 return (enum hovedret)(rand()%MAXHOVEDRET);
}

enum dessert randDessert() {
  return (enum dessert)(rand()%MAXDESSERT);
}
int main(void) {
  srand(time(NULL));

  return EXIT_SUCCESS;
}
