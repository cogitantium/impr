#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define FILENAME "data.txt"
#define READMODE "r"
#define ENTRIES 790
#define LINELENGTH 150
#define NAMELENGTH 50
#define SECSINHOUR 3600
#define SECSINMIN 60

typedef struct {
  char raceName[NAMELENGTH];  /* name of race, probably enumerate this */
  char fullName[NAMELENGTH];
  char firstName[NAMELENGTH]; /* only lower case and capitalized */
  char lastName[NAMELENGTH]; /* specified as all caps in file */
  int age;
  char team[NAMELENGTH];
  char nationality[NAMELENGTH]; /* 3-char */
  int placement; /* 0 should reflect DNF*/
  char raceTime[NAMELENGTH]; /* create function for representing secs as nicely formatted time */
  int raceTimeSec;
  int points;
  int totalPoints;
} entry;

int countLines();
void readData(entry data[]);
void printData(entry data[], int entries);
int convertTime(char string[]);
void printRiderRange(entry data[], int entries, int age, char nationality[]);
void calculatePoints(entry data[], int entries);
void printTop(entry data[], int entries, int top);
void splitNames(char string[], char *firstName, char *lastName);
int enumeratePlacement(char string[]);
void printAttendants(entry data[], int entries, char nationality[]);
void printEntry(entry data[], int entries);
int countUniqueRiders(entry data[], int entries);
int compareTeams(const void * a, const void * b);
int compareName(const void * a, const void * b);
int compareTop(const void * a, const void * b);

/*assignments
  (X) find and print all BEL below 23 years
  (X) find and print all danish racers that have attended one or more races. Sort these after teams, secondly alphabetically on firstName
  (X) print the 10 highest scoring riders, sort by points, secondly by age (youngest), thirdly alphabetically on lastName
  ( ) find, for each race, the team with most riders DNF or OTL
  ( ) find the nation, that did best in the races. sort by own choice
  ( ) find, in each race, the meadian raceTime, without DNF or OTL, a higher time is preferred, relative to M, than a lower time.
*/

int main(int argc, char *argv[]) {
  /* should use malloc() */
  /* entry data[ENTRIES]; */
  entry *data;
  int optAge, optTop, entries = countLines();
  char option, optNation[3];
  data = (entry *)malloc(entries * sizeof(entry));
  readData(data);
  calculatePoints(data, entries);

  if (argc > 2) {
    printf("Too many arguments supplied!\n");
    return EXIT_FAILURE;
  } else if(argc == 2 && !strcmp(argv[1], "--print")) {
      printRiderRange(data, entries, 23, "BEL");
      printAttendants(data, entries, "DEN");
      printTop(data, entries, 10);

  } else {
    printf("1: Print all entries read from file\n");
    printf("2: Find racers by nationality and max-age\n");
    printf("3: Find racers by nationality\n");
    printf("4: Print top n racers\n");
    printf("Choose an option: ");
    scanf(" %c", &option);
    if (option == '1') {
      printData(data, entries);
    }
    if (option == '2') {
      printf("Choose nationality, e.g. DEN or GBR: ");
      scanf(" %s", optNation);
      printf("Choose max-age: ");
      scanf(" %d", &optAge);
      printRiderRange(data, entries, optAge, optNation);
    } if (option == '3') {
        printf("Choose nationality, e.g. DEN or GBR: ");
        scanf(" %s", optNation);
        printAttendants(data, entries, optNation);
    } if (option == '4') {
        printf("Choose number of top-scoring riders to show: ");
        scanf(" %d", &optTop);
        printTop(data, entries, optTop);
    }
  }
  free(data);
  return EXIT_SUCCESS;
}

int countLines() {
  int i=0;
  char buffer[LINELENGTH];
  FILE *ifp;
  ifp = fopen(FILENAME, READMODE);

  while(fgets(buffer, LINELENGTH, ifp) != NULL) {
    i++;
  }
  fclose(ifp);
  return i;
}

void readData(entry data[]) {
  int i=0;
  char buffer[LINELENGTH], placement[5], firstName[25], lastName[25];
  FILE *ifp;
  ifp = fopen(FILENAME, READMODE);

  while(fgets(buffer, LINELENGTH, ifp) != NULL) {
    sscanf(buffer, "%s \" %[^\"]\" %d %[A-Z] %[A-Z] %[0-9DNFOTL] %[0-9:]",
    data[i].raceName,
    data[i].fullName, /* placeholder */
    &(data[i].age),
    data[i].team,
    data[i].nationality,
    placement, /* replaced with placeholder */
    data[i].raceTime);

    splitNames(data[i].fullName, firstName, lastName);
    memcpy(data[i].firstName, firstName, strlen(firstName)+1);
    memcpy(data[i].lastName, lastName, strlen(lastName)+1);

    data[i].placement = enumeratePlacement(placement);
    data[i].raceTimeSec = convertTime(data[i].raceTime);
    i++;
  }
  fclose(ifp);
}

int enumeratePlacement(char string[]) {
  if (strcmp(string, "DNF") == 0) return -1;
  else if (strcmp(string, "OTL") == 0) return 0;
  else return atoi(string);
  return -2;
}

void splitNames(char string[], char *firstName, char *lastName) {
  int i=0, n=1, stringLength = strlen(string);

  for (i=0; i<=stringLength; i++)
  if( (isupper(string[i]) && ((isupper(string[n]) || string[n] == '\'' )) ) ) {
    strncpy(firstName, string, i);
    firstName[i] = '\0';
    strcpy(lastName, &string[i]);
    break;
  } else {
    n++;
  }
}

void calculatePoints(entry data[], int entries) {
  int i=0, n=1, races=0, qualRiders=0, k=0;
  int endPos[4];

  /* find unique races in sorted array and store their end-position in array */
  for (i=0; i<entries; i++) {
    if (!strcmp(data[i].raceName, data[n].raceName) == 0 ) {
      endPos[races] = n;
      races++;
    }
    n++;
  }

  n=0;
  /* for each race do */
  for (i=0; i<races; i++) {

    /* count up qualRiders for all placements above 0 */
    for (; k<endPos[i]; k++) {
      /* printf("p: %3d ", data[k].placement); */
      if (data[k].placement > 0) {
        qualRiders++;
      }
    }

    /* for indexes in race do */
    for (; n<endPos[i]; n++) {
      /* assigning 2 points for finishing race, not DNF */
      if (data[n].placement > -1) {
        data[n].points += 2;
      }
      /* assign points for first, second and third place */
      if (data[n].placement <= 3 && data[n].placement >=1) {
        if (data[n].placement == 1) data[n].points += 8;
        if (data[n].placement == 2) data[n].points += 5;
        if (data[n].placement == 3) data[n].points += 3;
      }

      /* if rider finishes within timelimit, they're assigned (qualRacers - riderPlacement) / 17 points*/
      if (data[n].placement > 0) {
        data[n].points += ((qualRiders - data[n].placement) / 17);
      }
    }
    /* reset qualified racers, before calculating next race*/
    qualRiders = 0;
    /* reset n and k to next races beginning, before calculating next race */
    n=endPos[i];
    k=endPos[i];
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

  /* sort copied by name */
  qsort(copy, entries, sizeof(entry), compareName);

  /* for all entries in copy-array, do */
  for (i=0; i<entries; i++) {
    /* if current and next name in array are different, count up uniqueRiders and assign accumulated points to totalPoints in riders-array */
    if (!(strcmp(copy[i].fullName, copy[i+1].fullName) == 0)) {
      riders[uniqueRiders] = copy[i];
      riders[uniqueRiders].totalPoints = copy[i].points;
      uniqueRiders++;
    } else {
      copy[i+1].points += copy[i].points;
    }
  }

  qsort(riders, uniqueRiders, sizeof(entry), compareTop);

  printf("Printing top %d sorted by points, ascending age and last name.\n", top);
  for (i=0; i<top; i++) {
    printEntry(riders, i);
  }
  free(riders);
  free(copy);

}

int countUniqueRiders(entry data[], int entries) {
  int i, uniqueRiders=0;
  entry *riders;
  riders = (entry *)malloc(entries * sizeof(entry));

  /* deep copy array */
  for (i=0; i<entries; i++) {
    riders[i] = data[i];
  }

  qsort(riders, entries, sizeof(entry), compareName);

  for (i=0; i<entries; i++) {
    if (!(strcmp(riders[i].fullName, riders[i+1].fullName) == 0)) {
      uniqueRiders++;
    }
  }
  free(riders);
  return uniqueRiders;
}

int compareName(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;
  return strcmp((*rider1).fullName, (*rider2).fullName);
}

int compareTop(const void * a, const void * b) {
  entry *rider1 = (entry *)a;
  entry *rider2 = (entry *)b;

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

/* for debug purposes only */
void printData(entry data[], int entries) {
  int i;
  printf("##### PRINTING DATA #####\n");
  for (i=0; i<entries; i++) {
    printf("race:%19s | ", data[i].raceName);
    printf("name:%34s | ", data[i].fullName);
    printf("age:%3d | ", data[i].age);
    printf("team:%4s | ", data[i].team);
    printf("nation:%4s | ", data[i].nationality);
    printf("points: %2d | ", data[i].points);
    printf("placement:%4d | ", data[i].placement);
    printf("raceTime: %s\n", data[i].raceTime);

  }
}

void printEntry(entry data[], int index) {
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

void printRiderRange(entry data[], int entries, int age, char nationality[]) {
  int i;
  printf("Printing attendants from nationality: %s and age: %d\n", nationality, age);
  for (i=0; i<entries; i++) {
    if ((data[i].age < age) && (strcmp(data[i].nationality, nationality) == 0)) {
      printEntry(data, i);
    }
  }
}

void printAttendants(entry data[], int entries, char nationality[]) {
  int i, n=0;
  entry attendants[1000];
  /* for all entries, if nationality matches searched nationality, copy struct wholly into attendants struct-array and increment n */
  for (i=0; i<entries; i++) {
    if (strcmp(data[i].nationality, nationality) == 0) {
      attendants[n] = data[i];
      n++;
    }
  }

  qsort(attendants, n, sizeof(entry), compareTeams);
  printf("Printing attendants from: %s sorted by team, secondly by first name.\n", nationality);
  for (i=0; i<n; i++) {
    printEntry(attendants, i);
  }
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

int convertTime(char string[]) {
  int h, m, s;
  if (strcmp(string, "0") == 0) return 0;
  sscanf(string, "%d:%d:%d", &h, &m, &s);
  return h*SECSINHOUR + m*SECSINMIN + s;
}
