/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 02-03-2019 */

#ifndef __MONDE__
#define __MONDE__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "Pomme.h"
#include "Serpent.h"

/* Definition des constantes */
#define NB_POMMES 3

/* Definition de la structure */
typedef struct{
    Serpent serpent;
    Pomme pommes[NB_POMMES];
    int nb_pommes_actuelles;
    int nb_pommes_mangees;
}Monde;

/*
Fonction permettant de modifier la direction du joueur en fonction de la
touche appuyee.
Prend en parametre la structure du monde et l'identifiant de la touche appuyee.
Ne retourne rien.
*/
void modifie_direction(Monde *mon, MLV_Keyboard_button sym);

/*
Fonction permettant de verifier la direction dans laquelle on se dirige,
et d'attribuer les bonnes valeurs de directions aux deux adresses d'entiers
fournies dans les parametres.
Prend en parametre la structure du monde, et deux adresses d'entiers.
Ne retourne rien.
*/
void verifie_direction(Monde mon, int *dir_x, int *dir_y);

/*
Fonction permettant de vérifier le contenu de la case vers laquelle se
dirige le serpent.
Prend en parametre la structure du monde et deux entiers.
Retourne 0 si la case est vide, 1 si le serpent mange une pomme
et 2 si le serpent est mort.
*/
int verifie_contenu_case(Monde mon, int dir_x, int dir_y);

/*
Fonction permettant d'effectuer le deplacement du serpent sur le plateau.
Prend en parametre le monde genere.
Retourne 1 si tout s'est bien passe.
*/
int deplacer_serpent(Monde *mon);

/*
Fonction permettant de verifier si une pomme n'existe pas deja sur le plateau.
Prend en parametre la structure du monde et une pomme.
Retourne 0 si la pomme ne peut pas être generee, 1 sinon.
*/
int existe_pomme(Monde mon, Pomme pomme);

/*
Fonction permettant d'ajouter une pomme au monde.
Prend en parametre le monde genere.
Ne retourne rien.
*/
void ajouter_pomme_monde(Monde *mon);

/*
Fonction permettant de supprimer une pomme sur le plateau.
Prend en parametre le monde generee et le numero designant
la pomme a supprimer.
Ne retourne rien.
*/
void supprimer_pomme(Monde *mon, int numero_pomme);

/*
Fonction permettant de traiter le cas du serpent devant manger une pomme.
Prend en parametre la structure monde generee.
Retourne un entier (0 si c'est une pomme empoisonnee, 1 sinon).
*/
int manger_pomme_serpent(Monde *mon);

/*
Fonction permettant d'initialiser le monde voulu.
Prend en parametre un entier designant le nombre de pommes.
Retourne le monde genere.
*/
Monde init_monde(int nb_pommes);


#endif
