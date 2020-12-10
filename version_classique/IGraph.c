/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 02-03-2019 */
#include "IGraph.h"

void afficher_quadrillage(Monde *mon){
    int i, j;
    MLV_draw_filled_rectangle(0, 0, N*TAILLE_CASE, M*TAILLE_CASE, MLV_COLOR_LIGHT_SALMON);
    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            MLV_draw_rectangle(j*TAILLE_CASE, i*TAILLE_CASE,
                                (j+1)*TAILLE_CASE, (i+1)*TAILLE_CASE, MLV_COLOR_CHOCOLATE);
        }
    }
}

void afficher_pomme(Pomme *pom){
    MLV_draw_filled_circle((*pom).position.x*TAILLE_CASE + TAILLE_CASE/2,
            (*pom).position.y*TAILLE_CASE + TAILLE_CASE/2, (TAILLE_CASE/2)-4, MLV_COLOR_RED);


}


void afficher_serpent(Serpent *serpent){
    int i;
    MLV_draw_filled_circle((*serpent).corps[0].x*TAILLE_CASE + TAILLE_CASE/2,
    (*serpent).corps[0].y*TAILLE_CASE + TAILLE_CASE/2, (TAILLE_CASE/2), MLV_COLOR_GREEN4);
    for (i = 1; i < (*serpent).taille; i++){
        MLV_draw_filled_rectangle((*serpent).corps[i].x*TAILLE_CASE, (*serpent).corps[i].y*TAILLE_CASE,
                                    TAILLE_CASE, TAILLE_CASE, MLV_COLOR_GREEN4);
    }
}



void afficher_monde(Monde *mon){
    int i;
    MLV_draw_filled_rectangle(0, 0, TAILLE_FENETRE_X, TAILLE_FENETRE_Y, MLV_COLOR_BLACK);
    afficher_quadrillage(mon);
    for (i = 0; i < (*mon).nb_pommes_actuelles; i++){
        afficher_pomme(&(*mon).pommes[i]);
    }
    afficher_serpent(&(*mon).serpent);
    MLV_actualise_window();
}
