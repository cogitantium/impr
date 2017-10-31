#include <stdio.h>
#include <stdlib.h>
/* prototyping functions */
double* mergeArray(double *arrFirst, double *arrSecond, int worstCase, int arrFirstSize, int arrSecondSize, int *arrMergeSize);
void printArray(double *arr, int arrSize);

int main(void) {
  /* create and initialize sorted arrays */
  double arrFirst[5] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arrSecond[3] = {-1.8, 3.1, 6.3};
  /* calculating worst-case resulting array-size and elements in first and second array */
  int worstCase = ((sizeof(arrFirst) + sizeof(arrSecond)) / sizeof(double));
  int arrFirstSize = sizeof(arrFirst) / sizeof(double);
  int arrSecondSize = sizeof(arrSecond) / sizeof(double);
  /* prototyping arrMergeSize */
  int arrMergeSize;
  /* assigning resulting array from function to arrMerge */
  double *arrMerge = mergeArray(arrFirst, arrSecond, worstCase, arrFirstSize, arrSecondSize, &arrMergeSize);
  /* printArray function is invoked in conjunction with explanatory and structural printf-statements */
  printf("Merging first array:\t"); printArray(arrFirst, arrFirstSize);
  printf("\nand second array:\t"); printArray(arrSecond, arrSecondSize);
  printf("\nyields merged array:\t"); printArray(arrMerge, arrMergeSize); printf("\n");
  return EXIT_SUCCESS;
}

double* mergeArray(double *arrFirst, double *arrSecond, int worstCase, int arrFirstSize, int arrSecondSize, int *arrMergeSize) {
  int i, m = 0, n = 0, p = 0;
  /* dynamically allocating memory for temporary merging-array,
  as the number of resulting elements aren't known beforehand */
  double *tempMerge = (double*)malloc(worstCase * sizeof(double));
  /* prototyping resulting array for later memory allocation */
  double *arrMerge;
  /* COMMENT continue merging either index for arrFirst or arrSecond is out-of-bounds */
  while (m < arrFirstSize || n < arrSecondSize) {
    /* handling two out-of-bounds cases for indexes to arrFirst and arrSecond */
    if (m >= arrFirstSize) {
      tempMerge[p] = arrSecond[n];
      n++;
    } else if (n >= arrSecondSize) {
      tempMerge[p] = arrFirst[m];
      m++;
    } else if (arrFirst[m] < arrSecond[n]) {
      /* assign arrFirst at index m to tempMerge at index p */
      tempMerge[p] = arrFirst[m];
      m++;
    } else if (arrFirst[m] > arrSecond[n]) {
      /* assign arrSecond at index n to tempMerge at index p */
      tempMerge[p] = arrSecond[n];
      n++;
    } else if (arrFirst[m] == arrSecond[n]) {
      /* assign arrFirst at index m to tempMerge at index p */
      tempMerge[p] = arrFirst[m];
      /* count up both indexes, as we've reached a duplicate */
      m++; n++;
    }
    /* count tempMerge-array index up, as current element has been handled */
    p++;
  }
  /* assigning resulting array-size to arrMergeSize for printing */
  *arrMergeSize = p;
  /* allocate memory for resulting array, as number of elements are now known */
  arrMerge = (double*)malloc(p*sizeof(double));
  /* for each element in tempMerge, assign respective value to arrMerge to copy */
  for (i=p-1; i>=0; i--) {
    arrMerge[i] = tempMerge[i];
  }
  free(tempMerge);
  return arrMerge;
}
void printArray(double *arr, int arrSize) {
  int i;
  /* prints elements in array with mathematical notation through conditional statements */
  for (i=0; i<=(arrSize-1); i++) {
    printf("%s",(i==0)?"{":"");
    printf("%2.2f%s", arr[i], (i==arrSize-1)?"}":", ");
  }
}
