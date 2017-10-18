#include <stdio.h>

int main(void) {

  int v = 8, w = 5,
      r, s;
    
  r = v = w;     /* r kan ikke sættes lig med v og herefter w, da variablerne v og w allerede er defineret */
    printf("r=%d, s=%d, v=%d, w=%d", r , s , v , w );
  r = v + w;     /* r sættes lig v og w, derved er r=13 */

  r + v = w;     /* omvendt stilling af assignment, venstre til højre er default - desuden er v udefineret */

  r + (v = w);   /* først og fremmest er v og w ikke ens, desuden vi denne prioritet resultere i r + vw, nonsens */

  return 0;
}
