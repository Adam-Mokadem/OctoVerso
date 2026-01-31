#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "verif.h"
#include "rail.h"
#include "mains.h"

#define TAILLE_MAIN 12  
#define TAILLE_MAIN_MAX 16
#define TAILLE_RAIL 8  
#define TAILLE_PREMIER_MOT 4
#define TAILLE_MAX_MOT 15  // Le mot le plus grand du dictionnaire "ABANDONNASSIONS"
#define NOMBRE_LETTRES 88  




// Fonction pour saisir un mot valide et vérifier qu'il existe dans le dictionnaire  
void saisir_mot(char mot[], char main[], int numero_joueur, int tour_compteur) {
    int valide = 0;
    int faisable = 0;

    while (!valide || !faisable) {
        printf("%u> ", numero_joueur);
        fgets(mot, TAILLE_PREMIER_MOT+2, stdin);
        mot[strcspn(mot, "\n")] = 0;

        // Valider la saisie du mot  
        valide = est_valide(mot, tour_compteur);
        faisable = mot_faisable(mot, main, tour_compteur);
        if (!valide || !faisable) {
            printf("Veuillez saisir un mot valide.\n");
            continue;
        }

        // Vérifier si le mot existe dans le dictionnaire  
        if (!existe_dans_dictionnaire(mot)) {
            valide = 0;  // Si le mot n'est pas dans le dictionnaire, redemander  
        }
    }
}



// Fonction pour gérer les tours des joueurs  
int tour(const char mot1[], const char mot2[], int tour_compteur) {
    if (tour_compteur == 0) {
        if (strcmp(mot1, mot2) < 0) {
            return 1;
        }
        else {
            return 2;
        }
    }
    tour_compteur++;
    if (tour_compteur % 2 == 0) {
        return 2;
    }
    else {
        return 1;
    }
}




void jeu(char rail_recto[], char rail_verso[], char main_joueur[], char main_adversaire[], int tour_compteur) {
    char commande[2], tmp[TAILLE_MAX_MOT + 2], extremite[TAILLE_MAX_MOT], reste_mot[TAILLE_MAX_MOT], nouveau_mot[TAILLE_MAX_MOT + 1];
    int taille_extremite = 0, compteur = 0, situation = 0, finalite = 0;

    while (finalite == 0) {
        if (tour_compteur == 1) {
            printf("1> ");
        }
        if (tour_compteur == 2) {
            printf("2> ");
        }
        if (scanf_s("%1s %s", commande, (unsigned int)sizeof(commande), tmp, (unsigned int)sizeof(tmp)) == 2) {
            if (commande[0] == '-') {
                if (isalpha(tmp[0]) && isupper(tmp[0])) {
                    if (echange(tmp, main_joueur) == 0) {
                        continue;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                int taille_tmp = strlen(tmp);
                if (tmp[0] == '(') {
                    situation = 1;
                    if (entree_mot_droite(tmp, extremite, reste_mot) == 0) {
                        continue;
                    }
                }
                else {
                    situation = 2;
                    if (entree_mot_gauche(tmp, reste_mot, extremite) == 0) {
                        continue;
                    }
                }

                taille_extremite = strlen(extremite);


                // Vérification pour R  
                if (strcmp(commande, "R") == 0) {
                    compteur = verif_rail(situation, taille_extremite, rail_recto, extremite, compteur);
                }
                // Vérification pour V  
                if (strcmp(commande, "V") == 0) {
                    compteur = verif_rail(situation, taille_extremite, rail_verso, extremite, compteur);
                }
            


                if ((compteur == taille_extremite) && mot_faisable(reste_mot, main_joueur, tour_compteur) && est_valide(reste_mot, tour_compteur)) {
                    if (situation == 1) {
                        strcpy_s(nouveau_mot, sizeof(nouveau_mot), extremite);
                        strcat_s(nouveau_mot, sizeof(nouveau_mot), reste_mot);
                    }
                    if (situation == 2) {
                        strcpy_s(nouveau_mot, sizeof(nouveau_mot), reste_mot);
                        strcat_s(nouveau_mot, sizeof(nouveau_mot), extremite);
                    }
                    if (!existe_dans_dictionnaire(nouveau_mot)) {
                        continue;
                    }
                    else {
                        supprimer_lettres_utilisees(reste_mot, main_joueur);
                    }
                }
                else {
                    continue;
                }
            }
        }

        else {
            printf("Entree invalide.\n");
            continue;
        }
        char lettre_a_donner[TAILLE_RAIL - 2];
        int taille_reste_mot = strlen(reste_mot);
        int taille_nouveau_mot = strlen(nouveau_mot);
        char stock[TAILLE_RAIL - 2];

        if (situation == 1) { // Le rail se décale vers la gauche
            if (strcmp(commande, "R") == 0) {
                decalage_rail_vers_gauche(taille_reste_mot, lettre_a_donner, rail_recto, rail_verso, nouveau_mot, taille_nouveau_mot, stock);
            }
            if (strcmp(commande, "V") == 0) { // Le rail se décale vers la droite
                decalage_rail_vers_gauche(taille_reste_mot, lettre_a_donner, rail_verso, rail_recto, nouveau_mot, taille_nouveau_mot, stock);
            }
        }
        if (situation == 2) { // Le rail se décale vers la droite
            if (strcmp(commande, "R") == 0) {
                decalage_rail_vers_droite(taille_reste_mot, lettre_a_donner, rail_recto, rail_verso, taille_nouveau_mot, stock, taille_extremite, nouveau_mot);
            }
            if (strcmp(commande, "V") == 0) {
                decalage_rail_vers_droite(taille_reste_mot, lettre_a_donner, rail_verso, rail_recto, taille_nouveau_mot, stock, taille_extremite, nouveau_mot);
            }
        }

        lettres_sortantes_vers_adversaire(main_adversaire, lettre_a_donner);

        tri_main(main_joueur);
        tri_main(main_adversaire);

        if (tour_compteur == 1) {
            afficher_main(main_joueur, main_adversaire);
        }
        if (tour_compteur == 2) {
            afficher_main(main_adversaire, main_joueur);
        }

        afficher_rails(rail_recto, rail_verso);

        finalite = 1;
    }
}
