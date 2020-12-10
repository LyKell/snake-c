/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 19-02-2019 */

#ifndef __POMME__
#define __POMME__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Serpent.h"

/* Definition de la structure */
typedef struct {
    Case position;
}Pomme;

/*
Fonction permettant de generer une pomme aleatoirement.
Prend en parametre 2 entiers et le nombre de pommes empoisonnees
sur le plateau.
Retourne la pomme generee.
*/
Pomme pomme_gen_alea(int n, int m);

#endif
