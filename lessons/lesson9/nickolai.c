#include <stdio.h>
#include <stdlib.h>

int main () {

    /* Setup of constants. Data is stored in arrays for SUPER EASY extendability */
    /* Last timeSize must be 1 */
    const int timeSizes[5] = { 604800, 86400, 3600, 60, 1 };
    const char * timeNames[16] = { "uge", "dag", "time", "minut", "sekund" };
    const char * timeNamesPlural[16] = { "uger", "dage", "timer", "minutter", "sekunder" };

    int i = 0; /* because ansi C .... */

    /* Calculate how many time units we are working with */
    int timeUnitCount = sizeof(timeSizes) / sizeof(int);

    /* Get input from user */
    int input;
    printf("Indtast et antal %s.\n", timeNamesPlural[timeUnitCount - 1]);
    scanf("%d", &input);

    /* Godkend ikke negative tal */
    if (input < 0) {
        printf("Godkender ikke negative tal.\n");
        return EXIT_SUCCESS;
    }

    /* Calculate values */
    int leftover = input;
    int values[timeUnitCount];
    for (i = 0; i < timeUnitCount; i++) {
        values[i] = leftover / timeSizes[i];
        leftover %= timeSizes[i];
    }

    /* Evaluate how many units are relevant */
    int relevantUnits = 0;
    for (i = 0; i < timeUnitCount; i++) {
        if (values[i] != 0) relevantUnits++;
    }

    /* Print */
    printf("%d %s svarer til: ", input, (input == 1) ? timeNames[timeUnitCount - 1] : timeNamesPlural[timeUnitCount - 1]);
    if (relevantUnits == 0) {
        printf("ingenting.\n");
    } else {
        for (i = 0; i < timeUnitCount; i++)
        {
            /*
            * Prints only values greater than 0.
            * Makes sure to use plural then value is greater than 1
            * Prints " og " between last two units, otherwise ", "
            */
            if (values[i] > 0) {
                printf("%d %s%s",
                    values[i],
                    (values[i] > 1) ? timeNamesPlural[i]: timeNames[i],
                    (relevantUnits == 1) ? "\n" :
                        (relevantUnits == 2) ? " og " : ", ");

                relevantUnits--;
            }
        }
    }

    return EXIT_SUCCESS;
}
