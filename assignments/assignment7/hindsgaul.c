#include <stdio.h>
#include <stdlib.h>

int main(void){
  double arrFirst[5] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arrSecond[3] = {-1.8, 3.1, 6.3};
  double arrMerge[6];
  int n = 0, i = 0, p = 0;
  int arrSecond_length = 2;

  while(p < 6){
    if(i > arrSecond_length){
      arrMerge[p] = arrFirst[n];
      n++;
    } else if(arrFirst[n] < arrSecond[i]){
      arrMerge[p] = arrFirst[n];
      n++;
    } else if(arrFirst[n] == arrSecond[i]){
      arrMerge[p] = arrFirst[n];
      n++;
      i++;
    }
    else{
      arrMerge[p] = arrSecond[i];
      i++;
    }
    printf("%.1lf\n", arrMerge[p]);
    p++;
  }

  return 0;
}
