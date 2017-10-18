#include <stdio.h>
#include <math.h>

int main(void) {
	int inside, outside;
	double r,x,y;
    printf("Please input coordinates for (x,y): ");
    scanf("%lf %lf", &x,&y);
    printf("Please input radius: ");
    scanf("%lf", &r);

    if (r == sqrt(x * x + y * y)) {
    	printf("The coordinate (%.2lf,%.2lf) is ON the circle defined by radius: %.2lf",x,y,r);
    } else if (r > sqrt(x * x + y * y)) {
    	printf("The coordinate (%.2lf,%.2lf) is INSIDE the circle defined by radius: %.2lf",x,y,r);
    } else {
    	printf("The coordinate (%.2lf,%.2lf) is OUTSIDE the circle defined by radius: %.2lf\n",x,y,r);
    }
return 0;
}