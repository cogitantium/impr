#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXFORRET 4
#define MAXHOVEDRET 4
#define MAXDESSERT 4

enum forret {guacamole,tarteletter,lakserulle,graeskarsuppe};
enum hovedret {gyldenkaal,hakkeboef,gullash,forloren_hare};
enum dessert {pandekager_med_is,gulerodskage,chokolademousse,citronfromage};
enum forret randForret();
enum hovedret randHovedret();
enum dessert randDessert();
char* transForret(enum forret a);
char* transHovedret(enum hovedret a);
char* transDessert(enum dessert a);

void maaltid() {
  int i;
  for (i=0;i<=24;i++) {
    printf("Menu: %2d ",i+1);
    printf("Forret: %s ",transForret(randForret()));
    printf("Hovedret: %s ",transHovedret(randHovedret()));
    printf("Dessert: %s\n",transDessert(randDessert()));
  }
}

enum forret randForret() {
  return (enum forret)(rand()%MAXFORRET);
}

enum hovedret randHovedret() {
  return (enum hovedret)(rand()%MAXHOVEDRET);
}

enum dessert randDessert() {
  return (enum dessert)(rand()%MAXDESSERT);
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
  return "";
}

char* transHovedret(enum hovedret a) {
  switch(a){
    case gyldenkaal:
        return "gyldenkaal";
        break;
    case hakkeboef:
        return "hakkeboef";
        break;
    case gullash:
        return "gullash";
        break;
    case forloren_hare:
        return "forloren hare";
        break;
  }
  return "";
}

char* transDessert(enum dessert a) {
  switch(a){
    case pandekager_med_is:
        return "pandekager med is";
        break;
    case gulerodskage:
        return "gulerodskage";
        break;
    case chokolademousse:
        return "chokolademousse";
        break;
    case citronfromage:
        return "citronfromage";
        break;
  }
  return "";
}

int main(void) {
  srand(time(NULL));
  maaltid();
  return EXIT_SUCCESS;
}
