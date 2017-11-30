/* remember credentials! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "cykelloeb-2017.txt"
#define READMODE "r"
#define MAXLINELENGTH 150
#define MAXNAMELENGTH 50
#define MAXNATIONS 50

typedef struct {
  char raceName[MAXNAMELENGTH];
  char fullName[MAXNAMELENGTH];
  char firstName[MAXNAMELENGTH];
  char lastName[MAXNAMELENGTH];
  int age;
  char team[MAXNAMELENGTH];
  char nationality[MAXNAMELENGTH];
  int placement;
  char raceTime[MAXNAMELENGTH];
  int points;
  int totalPoints;
} entry;

typedef struct {
  char nation[MAXNAMELENGTH];
  int points;
} nationEntry;

int countLines();
void readData(entry data[]);
void printRiderRange(entry data[], int entries, int age, char nationality[]);
void calculatePoints(entry data[], int entries);
void printTop(entry data[], int entries, int top);
void splitNames(char string[], char *firstName, char *lastName);
int enumeratePlacement(char string[]);
void printAttendants(entry data[], int entries, char nationality[]);
void printEntry(entry data[], int entries);
int countUniqueRiders(entry data[], int entries);
void printMedianRacetime(entry data[], int entries);
void printBestNation(entry data[], int entries, int top);
int compareTeams(const void * a, const void * b);
int compareName(const void * a, const void * b);
int compareTop(const void * a, const void * b);
int compareRaces(const void * a, const void * b);
int compareNation(const void * a, const void * b);
int comparePoints(const void * a, const void * b);

int main(int argc, char *argv[]) {
  /* declaring optional variables and initialising struct-array with variabel length */
  int optAge, optTop, entries = countLines();
  char option, optNation[3];
  entry *data;
  data = (entry *)malloc(entries * sizeof(entry));
  /* calls functions for reading data and calculating points */
  readData(data);
  calculatePoints(data, entries);

  if (argc > 2) {
    printf("Too many arguments supplied!\n");
    return EXIT_FAILURE;
  /* prints default functions with criteria specified in assignment */
  } else if(argc == 2 && !strcmp(argv[1], "--print")) {
      printRiderRange(data, entries, 23, "BEL");
      printAttendants(data, entries, "DEN");
      printTop(data, entries, 10);
      printBestNation(data, entries, 1);
      printMedianRacetime(data, entries);
  /* user dialogue prompting for custom input to each function */
  } else {
    printf("1: Find riders by nationality and max-age\n");
    printf("2: Find riders by nationality\n");
    printf("3: Print top n riders\n");
    printf("5: Print highest scoring nation\n");
    printf("6: Print median times for all races\n");
    printf("q: Quit program\n");
    printf("Choose an option: ");
    scanf(" %c", &option);
    if (option == 'q') {
      return EXIT_SUCCESS;
    } if (option == '1') {
      printf("Choose nationality, e.g. DEN or GBR: ");
      scanf(" %s", optNation);
      printf("Choose riders aged below: ");
      scanf(" %d", &optAge);
      printRiderRange(data, entries, optAge, optNation);
    } if (option == '2') {
      printf("Choose nationality, e.g. DEN or GBR: ");
      scanf(" %s", optNation);
      printAttendants(data, entries, optNation);
    } if (option == '3') {
      printf("Choose number of top-scoring riders to show: ");
      scanf(" %d", &optTop);
      printTop(data, entries, optTop);
    } if (option == '5') {
      printf("Choose number of top-scoring nations to show: ");
      scanf(" %d", &optTop);
      printBestNation(data, entries, optTop);
    } if (option == '6') {
      printMedianRacetime(data, entries);
    }
  }
  /* freeing allocated memory before exiting successfully */
  free(data);
  return EXIT_SUCCESS;
}

int countLines() {
  int i=0;
  char buffer[MAXLINELENGTH];
  FILE *ifp;
  ifp = fopen(FILENAME, READMODE);
  /* while a new line exists in file, increment i */
  while(fgets(buffer, MAXLINELENGTH, ifp) != NULL) {
    i++;
  }
  fclose(ifp);
  return i;
}

void readData(entry data[]) {
  int i=0;
  char buffer[MAXLINELENGTH], placement[5], firstName[25], lastName[25];
  FILE *ifp;
  ifp = fopen(FILENAME, READMODE);

  while(fgets(buffer, MAXLINELENGTH, ifp) != NULL) {
    sscanf(buffer, "%s \" %[^\"]\" %d %[A-Z] %[A-Z] %[0-9DNFOTL] %[0-9:]",
    data[i].raceName,
    data[i].fullName,
    &(data[i].age),
    data[i].team,
    data[i].nationality,
    placement, /* placeholder for enumeration in same cycle */
    data[i].raceTime);
    /* split names correctly and use output parameters for copying in same loop */
    splitNames(data[i].fullName, firstName, lastName);
    strcpy(data[i].firstName, firstName);
    strcpy(data[i].lastName, lastName);
    /* using char-array as placeholder for placement, to retain an int representing placement */
    data[i].placement = enumeratePlacement(placement);
    i++;
  }
  fclose(ifp);
}

int enumeratePlacement(char string[]) {
  /* using -1 and 0 to represent DNF or OTL rider-placement */
  if (strcmp(string, "DNF") == 0) return -1;
  else if (strcmp(string, "OTL") == 0) return 0;
  /* using atoi() for converting numeral-characters to int-type */
  else return atoi(string);
}

void splitNames(char string[], char *firstName, char *lastName) {
  int i=0, strLen = strlen(string);
  for (i=0; i<=strLen; i++) {
    /* when evaluated true, we've found i to be index of first lastName char */
    if ( isupper(string[i]) && (isupper(string[i+1]) || string[i+1] == '\'') ) {
      /* copying string into firstName until i and replacing last char with null-character */
      strncpy(firstName, string, i-1);
      firstName[i] = '\0';
      /* copying string from i to null-character into lastName*/
      strcpy(lastName, &string[i]);
    }
  }
}

void calculatePoints(entry data[], int entries) {
  int i=0, n=0, races=0, qualRiders=0, k=0;
  int endPos[4];

  /* find unique races in sorted array and store their end-position in array */
  for (i=0; i<entries; i++) {
    /* if raceName at i and i+1 isn't equal, we've found a new race */
    if (!strcmp(data[i].raceName, data[i+1].raceName) == 0 ) {
      /* save last index position in int-array and increment races */
      endPos[races] = i+1;
      races++;
    }
  }

  /* for each race, do */
  for (i=0; i<races; i++) {

    /* count up qualifying riders with placements above 0 for current race */
    for (; k<endPos[i]; k++) {
      if (data[k].placement > 0) {
        qualRiders++;
      }
    }

    /* for entries in current race, do */
    for (; n<endPos[i]; n++) {
      /* adding 2 points for finishing race, though not DNF */
      if (data[n].placement > -1) {
        data[n].points += 2;
      }
      /* adding points for first, second and third place */
      if (data[n].placement <= 3 && data[n].placement >=1) {
        if (data[n].placement == 1) data[n].points += 8;
        if (data[n].placement == 2) data[n].points += 5;
        if (data[n].placement == 3) data[n].points += 3;
      }

      /* if rider finishes within timelimit, add (qualRacers - riderPlacement) / 17 points */
      if (data[n].placement > 0) {
        data[n].points += ((qualRiders - data[n].placement) / 17);
      }
    }
    /* reset qualified racers, before calculating next race*/
    qualRiders = 0;
    /* reset n and k to next races beginning, before calculating next race */
    n=endPos[i]; k=endPos[i];
  }
}

void printTop(entry data[], int entries, int top) {
  int i, uniqueRiders=0;
  entry *riders, *copy;
  riders = (entry *)malloc(countUniqueRiders(data, entries) * sizeof(entry));
  copy = (entry *)malloc(entries * sizeof(entry));

  /* deep copy array */
  for (i=0; i<entries; i++) {
    copy[i] = data[i];
  }

  /* sort copy-array by name */
  qsort(copy, entries, sizeof(entry), compareName);

  /* for all entries in copy-array, do */
  for (i=0; i<entries; i++) {
    /* if current and next name in array are different, we've found the last entry */
    if (!strcmp(copy[i].fullName, copy[i+1].fullName) == 0) {
      /* copy full entry into riders-array */
      riders[uniqueRiders] = copy[i];
      /* assign accumulated points to totalPoints member of array */
      riders[uniqueRiders].totalPoints = copy[i].points;
      uniqueRiders++;
    } else {
      /* accumulate given points in next member relative to i */
      copy[i+1].points += copy[i].points;
    }
  }
  /* sorting riders-array by points, age and lastly by lastName */
  qsort(riders, uniqueRiders, sizeof(entry), compareTop);

  /* printing top n riders */
  printf("\nPrinting top %d riders sorted by points, ascending age and lastly by last name.\n", top);
  for (i=0; i<top; i++) {
    printEntry(riders, i);
  }
  /* free memory allocated upon completion */
  free(riders); free(copy);
}

int countUniqueRiders(entry data[], int entries) {
  int i, uniqueRiders=0;
  entry *riders;
  riders = (entry *)malloc(entries * sizeof(entry));

  /* deep copy array */
  for (i=0; i<entries; i++) {
    riders[i] = data[i];
  }
  /* sort riders-array by name */
  qsort(riders, entries, sizeof(entry), compareName);

  for (i=0; i<entries; i++) {
    /* if following name is different, we've found another rider */
    if (!(strcmp(riders[i].fullName, riders[i+1].fullName) == 0)) {
      uniqueRiders++;
    }
  }
  /* free allocated memory and return number of unique riders */
  free(riders);
  return uniqueRiders;
}

void printMedianRacetime(entry data[], int entries) {
  int i, n=0, endPos[4], medianIndex, races=0, finishedRiders=0;
  /* allocating sufficient memory for race-array */
  entry *race;
  race = (entry *)malloc(entries * sizeof(entry));

  /* find unique races in sorted array and store their end-position in array */
  for (i=0; i<entries; i++) {
    if (!strcmp(data[i].raceName, data[i+1].raceName) == 0) {
      endPos[races] = i+1;
      races++;
    }
  }
  printf("\nPrinting median racetimes for %d races.\n", races);

  /* for each race do */
  for (i=0; i<races; i++) {

    /* for indexes in race do */
    for (; n<endPos[i]; n++) {
      /* if rider qualified, copy data-array wholly to race-array*/
      if (data[n].placement > 0) {
        race[finishedRiders] = data[n];
        finishedRiders++;
      }
    }
    /* calculate medianIndex, utilising the floor behaviour of
    integer division to get a lower index when finishedRiders is uneven */
    medianIndex = finishedRiders / 2;
    printf("race: %18s | median racetime is: %s\n", race[medianIndex].raceName, race[medianIndex].raceTime);

    /* resetting finishedRiders and n to next races beginning, before calculating next race */
    n=endPos[i]; finishedRiders=0;
  }
  /* freeing allocated memory upon completion */
  free(race);
}

void printBestNation(entry data[], int entries, int top) {
  int i, nations=0;
  char particle[3];
  entry *copy;
  nationEntry *nation;
  copy = (entry *)malloc(entries * sizeof(entry));
  /* allocating sufficient memory for nation-array */
  nation = (nationEntry *)malloc(MAXNATIONS * sizeof(nationEntry));

  /* deep copy array */
  for (i=0; i<entries; i++) {
    copy[i] = data[i];
  }

  /* sort array alphabetically by nation */
  qsort(copy, entries, sizeof(entry), compareNation);

  /* find unique nations in sorted array */
  for (i=0; i<entries; i++) {
    /* assigning name of nation to nation-arrays nation-member, if next nation is different */
    if (!strcmp(copy[i].nationality, copy[i+1].nationality) == 0) {
      strcpy(nation[nations].nation, copy[i].nationality);
      nations++;
      /* else add points of current index in copy-array to nation-array */
    } else {
      nation[nations].points += copy[i].points;
    }
  }
  /* sort nation-array by points, if equal, then alphabetically */
  qsort(nation, nations, sizeof(nationEntry), comparePoints);

  /* print all existing nations if user chooses more than exists */
  if (top>nations+1) top = nations;
  printf("\nPrinting highest scoring nation sorted by points and listed alphabetically.\n");
  for (i=0; i<top; i++) {
    /* switching for proper particle on placement */
    switch (i) {
      case 0: strcpy(particle, "st"); break;
      case 1: strcpy(particle, "nd"); break;
      case 2: strcpy(particle, "rd"); break;
      default: strcpy(particle, "th"); break;
    }
    printf("Nation %s came %d%s place with %d points.\n", nation[i].nation, i+1, particle, nation[i].points);
  }
  /* freeing allocated memory upon completion */
  free (copy);
}

/* printing index in struct-array if age- and nationality-member is smaller or matches parsed arguments */
void printRiderRange(entry data[], int entries, int age, char nationality[]) {
  int i;
  printf("Printing attendants from nationality: %s and age below: %d\n", nationality, age);
  for (i=0; i<entries; i++) {
    if ((data[i].age < age) && (strcmp(data[i].nationality, nationality) == 0)) {
      printEntry(data, i);
    }
  }
}

void printAttendants(entry data[], int entries, char nationality[]) {
  int i, n=0;
  entry *attendants;
  attendants = (entry *)malloc(entries * sizeof(entry));

  for (i=0; i<entries; i++) {
    /* if parsed nationality matches parsed argument, copy data-index wholly into attendants-index */
    if (strcmp(data[i].nationality, nationality) == 0) {
      attendants[n] = data[i];
      n++;
    }
  }
  /* sort attendants-array by team and secondly by firstName */
  qsort(attendants, n, sizeof(entry), compareTeams);
  /* prints attendants found nicely */
  printf("\nPrinting all entries for attendants from: %s sorted by team, secondly by first name.\n", nationality);
  for (i=0; i<n; i++) {
    printEntry(attendants, i);
  }
  free(attendants);
}

void printEntry(entry data[], int index) {
  /* prints a single entrys member-values, formatted nicely on one line */
  printf("race:%19s | ", data[index].raceName);
  printf("name:%34s | ", data[index].fullName);
  printf("age:%3d | ", data[index].age);
  printf("team:%4s | ", data[index].team);
  printf("nation:%4s | ", data[index].nationality);
  printf("points: %2d | ", data[index].points);
  printf("totalPoints: %2d | ", data[index].totalPoints);
  printf("placement:%4d | ", data[index].placement);
  printf("raceTime: %s\n", data[index].raceTime);
}

int compareTeams(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  /* if teams are equal, sort by firstname else sort by teams */
  if(strcmp((*rider1).team, (*rider2).team) == 0) {
    return strcmp((*rider1).firstName, (*rider2).firstName);
  }
  return strcmp((*rider1).team, (*rider2).team);
}

int compareRaces(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  /* if races are equal, sort by teams else by races */
  if(strcmp((*rider1).raceName, (*rider2).raceName) == 0) {
    return strcmp((*rider1).team, (*rider2).team);
  }
  return strcmp((*rider1).raceName, (*rider2).raceName);
}

int compareName(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  return strcmp((*rider1).fullName, (*rider2).fullName);
}

int comparePoints(const void * a, const void * b) {
  nationEntry *rider1 = (nationEntry *)a;
  nationEntry *rider2 = (nationEntry *)b;
  return (*rider2).points - (*rider1).points;
}

int compareNation(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  return strcmp((*rider1).nationality, (*rider2).nationality);
}

int compareTop(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  /* sorting by totalPoints, age and lastly lastName,
  if given criteria is equal check next criteria, else return difference */
  if ( (*rider1).totalPoints == (*rider2).totalPoints) {
    if ( (*rider1).age == (*rider2).age ) {
      return strcmp((*rider1).lastName, (*rider2).lastName);
    } else {
      return (*rider1).age - (*rider2).age;
    }
  } else {
    return (*rider2).totalPoints - (*rider1).totalPoints;
  }
}
