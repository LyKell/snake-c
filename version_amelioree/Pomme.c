/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 19-02-2019 */
#include "Pomme.h"

Pomme pomme_gen_alea(int n, int m, int *nb_pommes_empoisonnees){
    Pomme pomme;
    int type;
    pomme.position.x = rand() % n;
    pomme.position.y = rand() % m;

    /* Nouveau, gestion des types de pommes */
    if (*nb_pommes_empoisonnees >= 2){
        type = rand() % 2;
    }
    else {
        type = rand() % 3;
    }
    switch (type) {
        case 0: pomme.type = NORMALE; break;
        case 1: pomme.type = DOREE; break;
        case 2: pomme.type = EMPOISONNEE; *nb_pommes_empoisonnees += 1; break;
        default: pomme.type = NORMALE;
    }
    return pomme;
}
