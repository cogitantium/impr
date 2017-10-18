#include <stdio.h>

int main(void)
{

int inputseconds, minutes, hours, days, weeks, seconds;

    printf("This programme calculates seconds to weeks, days, hours and minutes.\nNow input seconds:");
	scanf("%d", &inputseconds);

    minutes = inputseconds/60;
    hours   = minutes/60;
    days    = hours/24;
    weeks   = days/7;

    seconds = inputseconds%60;
    minutes = minutes%60;
    hours   = hours%24;
    days    = days%7; 

printf("From the amount of input seconds, the programme has calculated that there are:\n%d weeks, %d days, %d hours, %d minutes, and %d seconds in all\n", weeks, days, hours, minutes, seconds);

   return 0;
}
