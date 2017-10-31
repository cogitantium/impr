#include <stdio.h>
#include <stdlib.h>

/* prototyping of functions*/

int main(void) {

  /* create and initialize sorted arrays */
  double arrFirst[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arrSecond[] = {-1.8, 3.1, 6.3};
  int worstCase = (sizeof(arrFirst) + sizeof(arrSecond)) / sizeof(double);
  double *arrMerge = (double*)malloc(worstCase);
  printf("Size of a double in bytes: %ld\n", sizeof(double));
  printf("Size of arrFirst: %ld\n", sizeof(arrFirst)/sizeof(double));
  printf("Size of arrSecond: %ld\n", sizeof(arrSecond)/sizeof(double));
  printf("Size of arrMerge: %ld\n", sizeof(arrMerge)/sizeof(double));

  int n = 0, i = 0, j = 0;
  int arr2_length = 2;

  while(j < 6){
    if(i > arr2_length){
      arrMerge[j] = arrFirst[n];
      n++;
    }
    else if(arrFirst[n] < arrSecond[i]){
      arrMerge[j] = arrFirst[n];
      n++;
    }
    else if(arrFirst[n] == arrSecond[i]){
      arrMerge[j] = arrFirst[n];
      n++;
      i++;
    }
    else{
      arrMerge[j] = arrSecond[i];
      i++;
    }
    printf("%.1lf\n", arrMerge[j]);
    j++;
  }
    printf("Size of arrMerge: %ld\n", sizeof(arrMerge)/sizeof(double));

  return EXIT_SUCCESS;
}
