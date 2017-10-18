#include <stdio.h>
/* import af stdio-biblioteket, til printf og scanf */
#include <stdlib.h>
/* import af stdlib-bibliotektet, til variable, som EXIT_SUCCESS */
#define SEC_PER_MIN 60
#define MIN_PER_HR 60
#define HR_PER_DAY 24
#define DAY_PER_WEEK 7

int main(void){
    int sekunder,minutter,timer,dage,uger,tid,rest;
        /* variable for enheder samt inputtid og løbende rest, initialiseres som heltal */   
    printf("Input venligst hele sekunder: ");
    scanf("%d", &tid);
        /* bruger promptes for sekunder og der scannes som integer */
    sekunder=tid%60;
        /* rest ved "inputtid modulus 60" sættes til sekunder */
    rest=tid/60;
        /* tiden divideres med 60, da sekunderne er fundet */
    minutter=rest%60;
        /* rest ved "resttid modulus 60" sættes til minutter */
    rest=rest/60;
        /* resttiden divideres med 60, da minutterne er beregnet */
    timer=rest%24;
        /* rest ved "resttid modulus 24" sættes til timer */
    rest=rest/24;
        /* resttiden divideres med 24, da timerne er beregnet */
    dage=rest%7;
        /* rest ved "resttid modulus 7" sættes til dage */
    uger=rest/7;
        /* da største enhed er uger, skriver vi resttiden her - svarende til w=time/(60*60*24*7) */
    printf("%d uger, %d dage, %d timer, %d minutter og %d sekunder svarer til %d sekunder.\n",uger,dage,timer,minutter,sekunder,tid);
        /* vi printer vores variable pænt ud som heltal og laver linjeskift til prompten */ 
return EXIT_SUCCESS;
}
