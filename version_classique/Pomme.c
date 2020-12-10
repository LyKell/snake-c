/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 19-02-2019 */
#include "Pomme.h"

Pomme pomme_gen_alea(int n, int m){
    Pomme pomme;
    pomme.position.x = rand() % n;
    pomme.position.y = rand() % m;
    return pomme;
}
