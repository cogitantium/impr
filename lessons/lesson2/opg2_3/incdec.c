#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5;
  int res1, res2, res3;
  
  i++; j--; ++k;
    /* da dette er et expression statement, er det lige fedt, med post/prefix, strengen evalueres og udføres */
  printf("i: %d, j: %d, k: %d\n", i,j,k);
    /* der printes værdierne ud, som beskrevet i overstående kommentar */
  res1 = --i;
    /* prefix decrement 3 */
  res2 = j++;
    /* postfix increment 3 */
  res3 = --k;
    /* prefix decrement 5 */

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3);
    /* res{1..3} printes */
  printf("i: %d, j: %d, k: %d\n", i,j,k);
    /* i,j,k printes */
  return 0;
}
