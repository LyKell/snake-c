/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 19-02-2019 */

#ifndef __SERPENT__
#define __SERPENT__

/* Inclusion des bibliotheques necessaires */
#include <stdio.h>
#include <stdlib.h>

/* Definition des constantes */
#define N 64
#define M 32

/* Definition des structures */
typedef struct {
    int x, y;
} Case;

typedef enum {
    NORD,
    SUD,
    EST,
    OUEST
} Direction;

typedef struct {
    Direction direction;
    int taille;
    Case corps[N*M];
} Serpent;

/*
Fonction permettant d'initialiser le serpent.
Ne prend rien en parametre.
Retourne le serpent genere.
*/
Serpent init_serpent(void);

#endif
