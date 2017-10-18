#include <stdio.h>
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (SECONDS_PER_MINUTE * 60)

int main(void){
  int input_seconds, seconds, minutes, hours, rest_seconds;

  /* Prompt for input: */
  printf("Read a non-negative number of seconds: ");
  scanf("%d", &input_seconds);

  /* Calculate the hours (in the interval 0..23) */
  hours = input_seconds / SECONDS_PER_HOUR;
  rest_seconds =  input_seconds % SECONDS_PER_HOUR;

  /* Calculate the minutes (in the interval 0..59) and the remaining seconds (in the interval 0..59) */
  minutes = rest_seconds / SECONDS_PER_MINUTE;
  seconds = rest_seconds % SECONDS_PER_MINUTE;

  if (input_seconds > 1) {
    printf("%d sekunder svarer til ", input_seconds);
  } else if (input_seconds == 1) {
    printf("%d sekund svarer til ", input_seconds);
  } else {
    printf("");
  }

  if (hours > 1) {
    printf("%d timer", hours);
    if (minutes >= 1 && seconds >= 1) {
    printf(", ");
    } else if (minutes > 1 && seconds < 1) {
      printf("og");
    } else if (minutes < 1 && seconds > 1) {
      printf("og");
    }
  } else if (hours == 1) {
    printf("%d time", hours);
    if (minutes >= 1 && seconds >= 1) {
    printf(", ");
    } else if (minutes > 1 && seconds < 1) {
      printf("og");
    } else if (minutes < 1 && seconds > 1) {
      printf("og");
    }
  } else {
    printf("");
  }

  if (minutes > 1) {
    printf("%d minutter", minutes);
    if (seconds >= 1) {
      printf(" og ");
    } else if (seconds < 1) {
      printf("");
    }
  } else if (minutes == 1) {
    printf("%d minut");
    if (seconds >= 1) {
      printf(" og  ");
    } else if (seconds < 1) {
      printf("");
    }
  } else {
    printf("");
  }

  if (seconds > 1) {
    printf("%d sekunder", seconds);
  } else if (seconds == 1) {
    printf("%d sekund", seconds);
  } else {
    printf("");
  }

  return 0;
}
