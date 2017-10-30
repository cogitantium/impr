#include <stdio.h>
#include <stdlib.h>

/* prototyping of functions*/

int main(void) {

  /* create and initialize sorted arrays */
  int
  double arrFirst[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arrSecond[] = {-1.8, 3.1, 6.3};
  int worstCase = (sizeof(arrFirst) + sizeof(arrSecond)) / sizeof(double);
  double *arrMerge = (double*)malloc(worstCase);
  mergeArray(worstCase, arrFirst, arrSecond, arr);
  /* */
  return EXIT_SUCCESS;
}

void mergeArray(int worstCase, double arrFirst[], double arrSecond[], arrMerge[]) { /* how to parse arrays as parameters */
  int m = 0, n = 0, p = 0;
  double tempMerge[sizeof(arrFirst) + sizeof(arrSecond)]
  while (length <= worst case) {
    if (arrFirst[m] < arrSecond[n]) {
      /* put arrFirst place m into tempMerge */
      tempMerge[p] = arrFirst[m];
      m++;
    } else if (arrFirst[m] > arrSecond[n]) {
      /* put arrSecond place n into tempMerge */
      tempMerge[p] = arrSecond[n];
      n++;
    } else if (arrFirst[m] == arrSecond[n]){
      /* put arrFirst place m into temp merge */
      tempMerge[p] = arrFirst[m];
      m++; n++;
    }
    /* count elements in tempMerge */
    /* create pointer-array with tempMerge elements*/

    for (i=sizeof(tempMerge); i<=0; i--) {
      /* transfer tempMerge into finalMerge */
    }

    /* done */
  }
}

/* case handling
1 the first array is exhausted first
2 the second array is exhausted first
3 the two arrays are exhausted at the same time
returns case as integer
*/
