#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* merge(double *arr1, int arr1_size, double *arr2, int arr2_size, int *out_size);
void print_arr(double *arr, int size);

int main(void)
{
    /* Hard coded arrays for testing */
    const int arr1_size = 5;
    const int arr2_size = 4;
    double arr1[5] = { 1.2, 2., 4.6, 10.125, 50};
    double arr2[4] = {0.1, 2., 6.9, 17.};

    /* Merge arrays */
    int merged_size;
    double *merged = merge(arr1, arr1_size, arr2, arr2_size, &merged_size);

    /* Print everything */
    printf("Array #1: ");
    print_arr(arr1, arr1_size);
    printf("\nArray #2: ");
    print_arr(arr2, arr2_size);
    printf("\nMerged array: ");
    print_arr(merged, merged_size);
    printf("\n");

    free(merged);
    return 0;
}

/* Merges the content of two (ascending order) arrays. Values that appear in both arrays will not be duplicated. The resulting array will also be ascending order */
double* merge(double *arr1, int arr1_size, double *arr2, int arr2_size, int *out_size) {
    int i = 0, a = 0, b = 0;
    /* the tmp array contains the values while the final length is unknown */
    double *out, *tmp = (double*) malloc((arr1_size + arr2_size) * sizeof(double));
    assert(tmp != NULL);

    while (a < arr1_size || b < arr2_size) {
        if (a >= arr1_size) {           /* arr1 is exhausted */
            tmp[i] = arr2[b];
            b++;
        }
        else if (b >= arr2_size) {      /* arr2 is exhausted */
            tmp[i] = arr1[a];
            a++;
        }
        else if (arr1[a] == arr2[b]) {  /* arr1[a] and arr2[b] is the same */
            tmp[i] = arr1[a];
            a++; b++;
        }
        else if (arr1[a] > arr2[b]) {   /* arr1[a] is biggest */
            tmp[i] = arr2[b];
            b++;
        }
        else {                          /* arr2[b] is biggest */
            tmp[i] = arr1[a];
            a++;
        }
        i++;
    }

    /* create merged array with correct length and copy values from tmp */
    out = (double*) malloc(i * sizeof(double));
    for (a = 0; a < i; a++) {
        out[a] = tmp[a];
    }

    free(tmp);
    if (out_size != NULL) *out_size = i;
    return out;
}

/* Prints an array with the corret format */
void print_arr(double *arr, int size) {
    int i;
    printf("{ ");
    for (i = 0; i < size; i++) {
        printf("%.3f%s ", arr[i], i < size - 1 ? "," : "");
    }
    printf("}");
}
