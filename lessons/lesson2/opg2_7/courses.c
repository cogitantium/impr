#include <stdio.h>

int main(void) {

  int courses = 1, groups, students = 176,
      average_pr_group;

  /* The variable groups is uninitialized */

  average_pr_group = students / groups;

  printf("Groups: %d\n", groups);

  printf("There are %d students pr. group in %d course(s)\n", 
         average_pr_group, courses);
  
  return 0;
  /* Floating point exception (core dumped) */
}
