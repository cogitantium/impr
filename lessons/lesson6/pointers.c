#include <stdio.h>

int main() {
    /* Kompiler programmet og se/forstå hvad der sker mellem de to printf*/

    int a = 10, b = 999;
    int *p = &a;

    printf("Values before:\n  a = %d\n  b = %d\n  *p = %d\n  p = %d\n", a, b, *p, p);

        *p = 30, p = &b;
    /*  Prøv at bytte overstående linje ud med én af følgende:
    *p = 2;
        a = 4;
        p = &b;
        *p = b;
        *p = *p + b;
        *p = 30, p = &b;
    */

    printf("Values after:\n  a = %d\n  b = %d\n  *p = %d\n  p = %d\n", a, b, *p, p);

    return 0;
}
