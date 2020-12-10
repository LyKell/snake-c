/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 02-03-2019 */
#include "Monde.h"


/* Fonctions auxiliaires */
void modifie_direction(Monde *mon, MLV_Keyboard_button sym){
    switch (sym){
        case 100 : (*mon).serpent.direction = SUD; break;
        case 113 : (*mon).serpent.direction = OUEST; break;
        case 115 : (*mon).serpent.direction = EST; break;
        case 122 : (*mon).serpent.direction = NORD; break;
        case 273 : (*mon).serpent.direction = NORD; break;
        case 274 : (*mon).serpent.direction = SUD; break;
        case 275 : (*mon).serpent.direction = EST; break;
        case 276 : (*mon).serpent.direction = OUEST; break;
        default : break;
    }
}

void verifie_direction(Monde mon, int *dir_x, int *dir_y){
    switch(mon.serpent.direction){
        case NORD : *dir_x = 0; *dir_y = 1; break;
        case SUD : *dir_x = 0; *dir_y = 1; break;
        case EST : *dir_x = 1; *dir_y = 0; break;
        case OUEST : *dir_x = 1; *dir_y = 0;break;
    }
}

int verifie_contenu_case(Monde mon, int dir_x, int dir_y){
    Case case_visee;
    int i, j;
    if (mon.serpent.direction == NORD || mon.serpent.direction == OUEST){
        case_visee.x = mon.serpent.corps[0].x - dir_x;
        case_visee.y = mon.serpent.corps[0].y - dir_y;
    }
    else {
        case_visee.x = mon.serpent.corps[0].x + dir_x;
        case_visee.y = mon.serpent.corps[0].y + dir_y;
    }

    /* Traitement du cas des pommes */
    for (i = 0; i < mon.nb_pommes_actuelles; i++){
        if (case_visee.x == mon.pommes[i].position.x
            && case_visee.y == mon.pommes[i].position.y){
            return 1;
        }
    }
    /* Traitement du cas de la collision avec le corps du serpent */
    for (j = 0; j < mon.serpent.taille; j++){
        if (case_visee.x == mon.serpent.corps[j].x
            && case_visee.y == mon.serpent.corps[j].y){
            return 2;
        }
    }

    /* Traitement du cas de la collision avec un mur */
    if ((case_visee.x < 0 || case_visee.x >= N) || (case_visee.y < 0 || case_visee.y >= M)){
        return 2;
    }

    /* Traitement de la case vide */
    return 0;

}





/* Fonctions Monde - serpent */
int deplacer_serpent(Monde *mon){
    int dir_x, dir_y, i;
    verifie_direction(*mon, &dir_x, &dir_y);
    for (i = ((*mon).serpent.taille)-1; i > 0; i--){
        (*mon).serpent.corps[i] = (*mon).serpent.corps[i-1];
    }
    if ((*mon).serpent.direction == NORD || (*mon).serpent.direction == OUEST){
        (*mon).serpent.corps[i].x -= dir_x;
        (*mon).serpent.corps[i].y -= dir_y;
    }
    else {
        (*mon).serpent.corps[i].x += dir_x;
        (*mon).serpent.corps[i].y += dir_y;
    }

    return 1;
}





/* Fonctions Monde - Pomme */
int existe_pomme(Monde mon, Pomme pomme){
    int i;
    for (i = 0; i < (mon).nb_pommes_actuelles; i++){
        if (pomme.position.x == mon.pommes[i].position.x
            && pomme.position.y == mon.pommes[i].position.y){
            return 0;
        }
    }
    for (i = 0; i < (mon).serpent.taille; i ++){
        if (pomme.position.x == mon.serpent.corps[i].x
            && pomme.position.y == mon.serpent.corps[i].y){
            return 0;
        }
    }
    return 1;
}


void ajouter_pomme_monde(Monde *mon){
    Pomme nouv_pomme;
    int resultat = 0;

    do {
        nouv_pomme = pomme_gen_alea(N,M);
        resultat = existe_pomme(*mon, nouv_pomme);
    } while (resultat == 0);

    (*mon).pommes[(*mon).nb_pommes_actuelles] = nouv_pomme;
    (*mon).nb_pommes_actuelles += 1;
}



void supprimer_pomme(Monde *mon, int num_pomme) {
	int i;
	for (i = num_pomme; i < NB_POMMES-1; i++) {
        (*mon).pommes[i] = (*mon).pommes[i+1];
	}
    (*mon).nb_pommes_actuelles -= 1;
}




/* Fonctions pommes - serpent */
int manger_pomme_serpent(Monde *mon) {
	int i, j;
	int dirX, dirY;
	verifie_direction(*mon, &dirX, &dirY);

	for (i = 0; i < NB_POMMES; i++) {
		if (((*mon).serpent.corps[0].x + dirX == (*mon).pommes[i].position.x &&
			(*mon).serpent.corps[0].y + dirY == (*mon).pommes[i].position.y)
            || ((*mon).serpent.corps[0].x - dirX == (*mon).pommes[i].position.x &&
    			(*mon).serpent.corps[0].y - dirY == (*mon).pommes[i].position.y)) {

				(*mon).nb_pommes_mangees += 1;

        	(*mon).serpent.taille++;
        	for (j = (*mon).serpent.taille - 1; j > 0; j--) {
        		(*mon).serpent.corps[j] = (*mon).serpent.corps[j - 1];
        	}
            (*mon).serpent.corps[j].x = (*mon).pommes[i].position.x;
            (*mon).serpent.corps[j].y = (*mon).pommes[i].position.y;

			supprimer_pomme(mon, i);
            ajouter_pomme_monde(mon);
		}
	}



	return 1;
}





/* Fonctions Monde */
Monde init_monde(int nb_pommes){
    Monde monde;
    int i;
    monde.serpent = init_serpent();
    for (i = 0; i < nb_pommes; i++){
        ajouter_pomme_monde(&monde);
    }
    monde.nb_pommes_mangees = 0;
    return monde;
}
