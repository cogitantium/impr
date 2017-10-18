#include <stdio.h>
/* import af stdio-biblioteket, til printf og scanf */
#include <stdlib.h>
/* import af stdlib-bibliotektet, til variable, som EXIT_SUCCESS */
#include <math.h>
/* import af math-biblioteket, til benyttelse af modulo som funktion */
#define SECSTOMIN 60
#define MINSTOHR 60
#define HRSTODAY 24
#define DAYSTOWEEK 7

#define SECSTOHR 3600
#define SECSTODAY 86400
#define SECSTOWEEK 604800
/* setting definitions */

int main(void){
    int secs,mins,hours,days,weeks,input;
        /* variable for enheder; secs,mins,hours,days,weeks samt inputtid og løbende rest, initialiseres som integer */
    printf("Please only input non-negative integers: ");
    scanf("%d", &input);

    secs=input%SECSTOMIN;
    mins=(input/SECSTOMIN)%SECSTOMIN;
    hours=(input/SECSTOHR)%HRSTODAY;
    /* days=(input/SECSTODAY)%DAYSTOWEEK;
    weeks=input/SECSTOWEEK; */

    if (mins == 0 && secs > 0 && hours > 0) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",secs,secs==1?"second":"seconds");
    } else if (hours == 0 && secs > 0 && mins > 0) {
      printf("%d %s and %d %s",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
    } else if (secs == 0 && mins > 0 && hours > 0 ) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes");
    } else {
      printf("%d %s, %d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
    }

/*

    if (input >= SECSTOWEEK) {
        printf("%d %s, %d %s, %d %s, %d %s and %d %s is equal to %d %s.\n",weeks,weeks==1?"week":"weeks",days,days==1?"day":"days",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds",input,secs==1?"sekund":"sekunder");
    } else if (input >= SECSTODAY) {
      printf("%d %s, %d %s, %d %s og %d %s is equal to %d %s.\n",days,days==1?"day":"days",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds",input,secs==1?"sekund":"sekunder");
    } else if (input >= SECSTOHR) {
      printf("HOURS");
    } else if (input >= SECSTOMIN) {
      printf("MINS");
    } else {
      printf("SECS");
    } */
            /* da største enhed er uger, skriver vi resttiden her - svarende til weeks=input/(60*60*24*7) */
  /*  printf("%d uger, %d dage, %d timer, %d minutter og %d %s svarer til %d %s.\n",weeks,days,hours,mins,secs,secs==1?"sekund":"sekunder",input,secs==1?"sekund":"sekunder"); */
        /* vi printer vores variable pænt ud som heltal og laver linjeskift til prompten */
return EXIT_SUCCESS;
}
