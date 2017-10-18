#include <stdio.h>
/* importing stdio library for printf and scanf functions */
#include <stdlib.h>
/* importing stdlib for variable EXIT_SUCCESS */
#define SECSTOMIN 60
#define SECSTOHR 3600
#define MINSTOHR 60
/* setting constants for use in conversion */
int main(void){
    int secs,mins,hours,input;
    /* variables initialised as intergers */
    printf("Please only input non-negative integers: ");
    scanf(" %d", &input);
    /* scanning seconds from user into input */
    secs=input%SECSTOMIN;
    mins=(input/SECSTOMIN)%SECSTOMIN;
    hours=input/SECSTOHR;
    /* calculating conversion from input in seconds to secs, mins and hours */
    if (secs>0 && mins>0 && hours>0) {
      printf("%d %s, %d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
      /* evaluating default case, if all variables are positive, first to save runtime */
    } else if (hours==0 && secs>0 && mins>0) {
      printf("%d %s and %d %s",mins,mins==1?"minute":"minutes",secs,secs==1?"second":"seconds");
    } else if (secs==0 && mins>0 && hours>0 ) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",mins,mins==1?"minute":"minutes");
    } else if (mins==0 && secs>0 && hours>0) {
      printf("%d %s and %d %s",hours,hours==1?"hour":"hours",secs,secs==1?"second":"seconds");
      /* evaluating three cases where two units have positive values and one is zero */
    } else if (mins>0 && secs==0 && hours==0) {
      printf("%d %s",mins,mins==1?"minute":"minutes");
    } else if (hours>0 && secs==0 && mins==0) {
      printf("%d %s",hours,hours==1?"hour":"hours");
    } else {
      printf("%d %s",secs,secs==1?"second":"seconds");
    }  /* evaluating three cases where one variable is positive and two are zero */
    printf(" is equal to %d %s.\n",input,input==1?"second":"seconds");
    /* singular/plural is handled above in print-function with conditional statements */
return EXIT_SUCCESS;
}
