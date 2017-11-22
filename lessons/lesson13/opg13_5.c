#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READMODE "r"
#define WRITEMODE "w"
#define MAX_NAME_LGT 60
struct person{
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
};

int main(void) {
  int i=0, n;
  struct person entry[20];
  char buffer[MAX_NAME_LGT];
  FILE *ifp, *ofp;

  ifp = fopen("in.txt", READMODE);
  ofp = fopen("out.txt", WRITEMODE);

  while(fgets(buffer, MAX_NAME_LGT, ifp) != NULL) {
    sscanf(buffer, " %[a-zA-Z] %[^,], %[^0-9] %d, %d %[^.]",
    entry[i].fornavn,
    entry[i].efternavn,
    entry[i].vejnavn,
    &(entry[i].vejnummer),
    &(entry[i].postnummer),
    entry[i].bynavn);
    i++;
  }

  for (n=0; n<i; n++) {
    printf("Fornavn: %s\n", entry[n].fornavn);
    printf("Efternavn: %s\n", entry[n].efternavn);
    printf("Vejnavn: %s\n", entry[n].vejnavn);
    printf("Vejnummer: %d\n", entry[n].vejnummer);
    printf("Postnummer: %d\n", entry[n].postnummer);
    printf("Bynavn: %s\n\n", entry[n].bynavn);
  }

  for (n=0; n<i; n++) {
    fprintf(ofp, "Fornavn: %s\n", entry[n].fornavn);
    fprintf(ofp, "Efternavn: %s\n", entry[n].efternavn);
    fprintf(ofp, "Vejnavn: %s\n", entry[n].vejnavn);
    fprintf(ofp, "Vejnummer: %d\n", entry[n].vejnummer);
    fprintf(ofp, "Postnummer: %d\n", entry[n].postnummer);
    fprintf(ofp, "Bynavn: %s\n\n", entry[n].bynavn);
  }

  fclose(ifp);
  fclose(ofp);

  return EXIT_SUCCESS;
}
