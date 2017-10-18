#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double p1_x,p1_y,p2_x,p2_y,p3_x,p3_y;
    /*double length_p12, length_p13, length_p23;*/
    printf("Enter x and y for p1: ");
    scanf(" %lf %lf", &p1_x, &p1_y);
    
    printf("Enter x and y for p2: ");
    scanf(" %lf %lf", &p2_x, &p2_y);

    printf("Enter x and y for p3: ");
    scanf(" %lf %lf", &p3_x, &p3_y);

    double length_p12 = sqrt(pow(p1_x - p2_x, 2) + pow(p1_y - p2_y, 2));
    double length_p13 = sqrt(pow(p1_x - p3_x, 2) + pow(p1_y - p3_y, 2));
    double length_p23 = sqrt(pow(p2_x - p3_x, 2) + pow(p2_y - p3_y, 2));

    double circumference = length_p12 + length_p13 + length_p23;

    printf("p1 = (%.2f, %.2f), p2 = (%.2f, %.2f), p3 = (%.2f, %.2f)\nlength_p12: %.2f\nlength_p13: %.2f\nlength_p23: %.2f\nCircumference: %.2f\n", p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, length_p12, length_p13, length_p23, circumference);

    return EXIT_SUCCESS;
}
