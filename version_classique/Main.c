/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 19-02-2019
 * Modification : 02-03-2019 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "Monde.h"
#include "IGraph.h"




/*
Fonction principale effectuant la boucle du programme, et gérant les variables
nécessaires au bon fonctionnement du programme.
Ne prend rien en parametre.
Retourne un entier 0 si tout s'est bien passe.
*/
int main(void){
    srand(time(NULL));
    Monde monde;
    int fin_partie = 0;
    int contenu_case, dir_x, dir_y;

    /* Uniquement pour le MLV_get_event */
    MLV_Event evenement;
    MLV_Keyboard_button sym;
    MLV_Keyboard_modifier mod;
    int unicode, x, y;
    char **texte = NULL;
	MLV_Input_box **input_box = NULL;
	MLV_Mouse_button bouton;
	MLV_Button_state etat;

    monde = init_monde(3);
    MLV_create_window("Snake","Snake", TAILLE_FENETRE_X, TAILLE_FENETRE_Y);

    afficher_monde(&monde);
    MLV_wait_keyboard(&sym, &mod, &unicode);

    while (fin_partie == 0){
        verifie_direction(monde, &dir_x, &dir_y);
        contenu_case = verifie_contenu_case(monde, dir_x, dir_y);
        switch (contenu_case){
            case 0 : deplacer_serpent(&monde); break;
            case 1 : manger_pomme_serpent(&monde); break;
            case 2 : fin_partie = 1; break;
        }

        afficher_monde(&monde);
        evenement = MLV_get_event(&sym, &mod, &unicode, texte, input_box, &x, &y, &bouton, &etat);
        if (evenement == MLV_KEY){
            modifie_direction(&monde, sym);
        }
        MLV_wait_milliseconds(300);
    }


    if (fin_partie == 1){
        char score[20];
        sprintf(score, "Score : %d", monde.nb_pommes_mangees);
        MLV_draw_adapted_text_box(
            ((N/2) - 3)*TAILLE_CASE,((M/2) - 1)*TAILLE_CASE,
            score,
            15,
            MLV_COLOR_BLACK, MLV_COLOR_INDIANRED, MLV_COLOR_WHITESMOKE,
            MLV_TEXT_CENTER
        );
        MLV_actualise_window();
        MLV_wait_seconds(5);
    }

    MLV_free_window();


    return 0;
}
