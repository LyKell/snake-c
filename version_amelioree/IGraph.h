/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 03-03-2019 */

#ifndef __IGRAPH__
#define __IGRAPH__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <MLV/MLV_all.h>
#include "Monde.h"

/* Definition des constantes */
#define TAILLE_FENETRE_X 1280
#define TAILLE_FENETRE_Y 640
#define TAILLE_CASE 20

/*
Fonction permettant d'afficher les high scores en debut de partie.
Ne prend rien en parametre.
Ne retourne rien.
*/
void afficher_score(void);

/*
Fonction permettant d'afficher le quadrillage du jeu.
Prend en parametre le monde genere.
Ne retourne rien.
*/
void afficher_quadrillage(Monde *mon);

/*
Fonction permettant d'afficher une pomme sur le plateau de jeu.
Prend en parametre une des pommes generees.
Ne retourne rien.
*/
void afficher_pomme(Pomme *pom);

/*
Fonction permettant d'afficher le serpent sur le plateau de jeu.
Prend en parametre le serpent genere.
Ne retourne rien.
*/
void afficher_serpent(Serpent *serpent);

/*
Fonction permettant d'afficher tous les elements du monde
(quadrillage, pommes, ...).
Prend en paramètre le monde genere.
Ne retourne rien.
*/
void afficher_monde(Monde *mon);


#endif
