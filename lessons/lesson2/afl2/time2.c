#include <stdio.h>
/* importing stdio library for printf and scanf functions */
#include <stdlib.h>
/* import af stdlib-bibliotektet, til variable, som EXIT_SUCCESS */
#define SECSTOMIN 60
#define MINSTOHR 60
#define HRSTODAY 24
#define DAYSTOWEEK 7

#define SECSTOHR 3600
/* setting definitions */

int main(void){
    int secs,mins,hours,input;
        /* variable for enheder; secs,mins,hours,days,weeks samt inputtid og løbende rest, initialiseres som integer */
    printf("Please only input non-negative integers: ");
    scanf("%d", &input);

    secs=input%SECSTOMIN;
    mins=(input/SECSTOMIN)%SECSTOMIN;
    hours=(input/SECSTOHR)%HRSTODAY;

    if (mins==0 && secs>0 && hours>0) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",secs,secs==1?"second":"seconds");
    } else if (hours==0 && secs>0 && mins>0) {
      printf("%d %s and %d %s",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
    } else if (secs==0 && mins>0 && hours>0 ) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes");
    } else if (secs>0 && mins>0 && hours>0) {
      printf("%d %s, %d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
    } else {
      printf("diller");
    }
return EXIT_SUCCESS;
}
