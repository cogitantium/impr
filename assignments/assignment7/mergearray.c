#include <stdio.h>
#include <stdlib.h>

/* prototyping of functions*/
double* mergeArray(double *arrFirst, double *arrSecond);

int main(void) {
  int i;
  /* create and initialize sorted arrays */
  double arrFirst[5] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arrSecond[3] = {-1.8, 3.1, 6.3};

  /* double *arrMerge = (double*)malloc(worstCase); */
  double *arrMerge = mergeArray(arrFirst, arrSecond);
  /* */
  for (i=sizeof(arrMerge)/sizeof(double); i>0; i--) {
    printf("%f\n", arrMerge[i]);
  }
  return EXIT_SUCCESS;
}

double* mergeArray(double *arrFirst, double *arrSecond) {
  int i, m = 0, n = 0, p = 0;
  printf("%d\n", sizeof(arrFirst));
  int worstCase = ((sizeof(arrFirst) + sizeof(arrSecond)) / sizeof(double));
  /* ISSUE HERE */
  double *tempMerge = (double*)malloc(worstCase * sizeof(double));
  double *arrMerge;
  int arrFirstSize = sizeof(arrFirst) / sizeof(double);
  int arrSecondSize = sizeof(arrSecond) / sizeof(double);

  while (p < worstCase) {
    if (m > arrFirstSize) {
      tempMerge[p] = arrSecond[n];
      n++;
    } else if (n > arrSecondSize) {
      tempMerge[p] = arrFirst[m];
      m++;
    } else if (arrFirst[m] < arrSecond[n]) {
      /* put arrFirst place m into tempMerge */
      tempMerge[p] = arrFirst[m];
      m++;
    } else if (arrFirst[m] > arrSecond[n]) {
      /* put arrSecond place n into tempMerge */
      tempMerge[p] = arrSecond[n];
      n++;
    } else if (arrFirst[m] == arrSecond[n]){
      /* put arrFirst place m into tempMerge */
      tempMerge[p] = arrFirst[m];
      m++; n++;
    }
    p++;
  }
  /* create pointer-array with tempMerge elements*/
  arrMerge = (double*)malloc(p*sizeof(double));
  for (i=p; i<=0; i--) {
    arrMerge[i] = tempMerge[i];
  }
  return arrMerge;
}
