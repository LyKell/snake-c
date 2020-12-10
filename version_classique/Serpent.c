/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 19-02-2019 */
#include "Serpent.h"

Serpent init_serpent(void){
    Serpent serpent;

    serpent.taille = 2;
    serpent.corps[0].x = N/2;
    serpent.corps[0].y = M/2;
    serpent.corps[1].x = (N/2)-1;
    serpent.corps[1].y = M/2;
    serpent.direction = EST;

    return serpent;
}
